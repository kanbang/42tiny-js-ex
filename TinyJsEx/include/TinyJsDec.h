
#pragma once
#include <string>

//////////////////////////////////////////////////////////////////////////
//需要将静态库TinyJs完全封装在dll内部，不对外暴露，否则在多个模块都导入TinyJs时，引用计数会出错引起崩溃

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