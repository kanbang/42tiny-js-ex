
#pragma once
#include <string>

//////////////////////////////////////////////////////////////////////////
//��Ҫ����̬��TinyJs��ȫ��װ��dll�ڲ��������Ⱪ¶�������ڶ��ģ�鶼����TinyJsʱ�����ü���������������

class CTinyJS;

template<typename C> class CScriptVarPointer;

class CScriptVarScopeFnc;
typedef CScriptVarPointer<CScriptVarScopeFnc> CFunctionsScopePtr;

//////////////////////////////////////////////////////////////////////////
TINY_JS_EX_API int			GetFuncArgumentInt		(const CFunctionsScopePtr &c, const std::string &name);
TINY_JS_EX_API long			GetFuncArgumentLong		(const CFunctionsScopePtr &c, const std::string &name);
TINY_JS_EX_API double		GetFuncArgumentDouble	(const CFunctionsScopePtr &c, const std::string &name);
TINY_JS_EX_API bool			GetFuncArgumentBool		(const CFunctionsScopePtr &c, const std::string &name);
TINY_JS_EX_API std::string	GetFuncArgumentString	(const CFunctionsScopePtr &c, const std::string &name);

//////////////////////////////////////////////////////////////////////////
TINY_JS_EX_API void			SetFuncReturnVar		(const CFunctionsScopePtr &c, int v);
TINY_JS_EX_API void			SetFuncReturnVar		(const CFunctionsScopePtr &c, long v);
TINY_JS_EX_API void			SetFuncReturnVar		(const CFunctionsScopePtr &c, double v);
TINY_JS_EX_API void			SetFuncReturnVar		(const CFunctionsScopePtr &c, bool v);
TINY_JS_EX_API void			SetFuncReturnVar		(const CFunctionsScopePtr &c, const std::string &v);


//////////////////////////////////////////////////////////////////////////
template <typename T>
inline T GetFuncArgument(const CFunctionsScopePtr &c, const std::string &name);

#define GetFuncArgumentType(Type, Fun)																	\
	template <> inline Type GetFuncArgument<Type>(const CFunctionsScopePtr &c, const std::string &name)	\
{																										\
	return Fun(c, name);																				\
}

GetFuncArgumentType(int,			GetFuncArgumentInt);
GetFuncArgumentType(long,			GetFuncArgumentLong);
GetFuncArgumentType(double,			GetFuncArgumentDouble);
GetFuncArgumentType(bool,			GetFuncArgumentBool);
GetFuncArgumentType(std::string,	GetFuncArgumentString);