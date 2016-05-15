#pragma once
#include <string>
#include <sstream>
#include <list>
#include "TinyJsDec.h"
#include "bind\fun_traits.h"

using namespace xtype;

//////////////////////////////////////////////////////////////////////////
inline std::string Int2String(int intData) 
{
	std::ostringstream str;
	str << intData;
	return str.str();
}

template <class TList>
inline std::string GetParamsStr()
{
	std::string sParams = "(";
	int nLen =  xtype::Length<TList>::value;
	for (int i=0; i<nLen; ++i)
	{
		if (i > 0)
		{
			sParams += ", ";
		}
		sParams += "p";
		sParams += Int2String(i);
	}
	sParams += ")";
	return sParams;
}

template <class T>
struct Stack
{
	static inline T get (const CFunctionsScopePtr &c, int index)
	{
		std::string name = "p";
		name += Int2String(index);
		return GetFuncArgument<T>(c, name);
	}
};


//////////////////////////////////////////////////////////////////////////
template <typename List, int nStart=0>
struct ArgList
{
};

template <int nStart>
struct ArgList <NoneType, nStart> : public TypeListValues <NoneType>
{
	ArgList (const CFunctionsScopePtr &c)
	{
	}
};

template <typename Head, typename Tail, int nStart>
struct ArgList <TypeList <Head, Tail>, nStart> : public TypeListValues <TypeList <Head, Tail> >
{
	ArgList (const CFunctionsScopePtr &c)
		: TypeListValues <TypeList <Head, Tail>> (Stack <Head>::get(c, nStart), ArgList <Tail, nStart+1> (c))
	{
	}
};


//////////////////////////////////////////////////////////////////////////
struct CallFunction
{
	virtual ~CallFunction() {}
	virtual void call(const CFunctionsScopePtr &c) = 0;
	virtual std::string func_params() = 0;
};

template <class Func, class ReturnType = typename FuncTraits <Func>::ReturnType>
struct CallFunctionImp : public CallFunction
{
	CallFunctionImp(Func fun) : m_fun(fun) {}

	typedef typename FuncTraits <Func>::Params Params;

	virtual void call (const CFunctionsScopePtr &c)
	{
		ArgList <Params> tvl(c);
		ReturnType ret = FuncTraits <Func>::call (m_fun, tvl);
		SetFuncReturnVar(c, ret);
	}

	virtual std::string func_params()
	{
		return GetParamsStr<Params>();
	}

protected:
	Func m_fun;
};

template <class Func>
struct CallFunctionImp <Func, void> : public CallFunction
{
	CallFunctionImp(Func fun) : m_fun(fun) {}

	typedef typename FuncTraits <Func>::Params Params;

	virtual void call (const CFunctionsScopePtr &c)
	{
		ArgList <Params> tvl(c);
		FuncTraits <Func>::call (m_fun, tvl);
	}

	virtual std::string func_params()
	{
		return GetParamsStr<Params>();
	}

protected:
	Func m_fun;
};

template <class Func, class ReturnType = typename FuncTraits <Func>::ReturnType>
struct CallMemFunctionImp : public CallFunction
{
	typedef typename FuncTraits <Func>::ClassType	ClassType;
	typedef typename FuncTraits <Func>::Params		Params;

	CallMemFunctionImp(ClassType *obj, Func fun) : m_obj(obj), m_fun(fun) {}
	virtual void call (const CFunctionsScopePtr &c)
	{
		ArgList <Params> tvl(c);
		ReturnType ret = FuncTraits <Func>::call (m_obj, m_fun, tvl);
		SetFuncReturnVar(c, ret);
	}

	virtual std::string func_params()
	{
		return GetParamsStr<Params>();
	}

protected:
	ClassType*	m_obj;
	Func		m_fun;
};

template <class Func>
struct CallMemFunctionImp <Func, void> : public CallFunction
{
	typedef typename FuncTraits <Func>::ClassType	ClassType;
	typedef typename FuncTraits <Func>::Params		Params;

	CallMemFunctionImp(ClassType *obj, Func fun) : m_obj(obj), m_fun(fun) {}
	virtual void call (const CFunctionsScopePtr &c)
	{
		ArgList <Params> tvl(c);
		FuncTraits <Func>::call (m_obj, m_fun, tvl);
	}

	virtual std::string func_params()
	{
		return GetParamsStr<Params>();
	}

protected:
	ClassType*	m_obj;
	Func		m_fun;
};

typedef std::list<CallFunction*>	listFunCall;

class TINY_JS_EX_API CTinyJsEx2
{
public:
	CTinyJsEx2();
	virtual ~CTinyJsEx2();

public:
	template<typename Fn>
	void AddFun(const std::string &str, Fn fun)
	{
		__AddFun(str, new CallFunctionImp<Fn>(fun));
	}

	template<typename T, typename Fn>
	void AddMemFun(const std::string &str, T *obj, Fn fun)
	{
		__AddFun(str, new CallMemFunctionImp<Fn>(obj, fun));
	}

	void AddVar(const std::string &name, const int &var);
	void AddVar(const std::string &name, const double &var);
	void AddVar(const std::string &name, const std::string &var);

	void		Execute (const char *Code, const std::string &File="", int Line=0, int Column=0);
	std::string Evaluate(const char *code, const std::string &File="", int Line=0, int Column=0);

	bool IsExpTrue(const std::string &exp);

protected:
	bool __AddFun(const std::string &str, CallFunction *fun_ptr);

protected:
	CTinyJS*	m_tiny_js_ptr;
	listFunCall	m_funList;
};



