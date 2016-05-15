#include "stdafx.h"
#include "TinyJsDec.h"
#include "TinyJS.h"

#ifdef _DEBUG
#pragma comment(lib,"..\\debug\\lib-tiny-js.lib")
#else
#pragma comment(lib,"..\\release\\lib-tiny-js.lib")
#endif // _DEBUG


//////////////////////////////////////////////////////////////////////////
int GetFuncArgumentInt(const CFunctionsScopePtr &c, const std::string &name)
{
	return c->getArgument(name)->toNumber().toInt32();
}

long GetFuncArgumentLong(const CFunctionsScopePtr &c, const std::string &name)
{
	return c->getArgument(name)->toNumber().toInt32();
}

double GetFuncArgumentDouble(const CFunctionsScopePtr &c, const std::string &name)
{
	return c->getArgument(name)->toNumber().toDouble();
}

bool GetFuncArgumentBool(const CFunctionsScopePtr &c, const std::string &name)
{
	return c->getArgument(name)->toNumber().toBoolean();
}

std::string GetFuncArgumentString(const CFunctionsScopePtr &c, const std::string &name)
{
	return c->getArgument(name)->toString();
}

//////////////////////////////////////////////////////////////////////////
void SetFuncReturnVar(const CFunctionsScopePtr &c, int v)
{
	c->setReturnVar(c->newScriptVar(v));
}

void SetFuncReturnVar(const CFunctionsScopePtr &c, long v)
{
	c->setReturnVar(c->newScriptVar(v));
}

void SetFuncReturnVar(const CFunctionsScopePtr &c, double v)
{
	c->setReturnVar(c->newScriptVar(v));
}

void SetFuncReturnVar(const CFunctionsScopePtr &c, bool v)
{
	c->setReturnVar(c->newScriptVar(v));
}

void SetFuncReturnVar(const CFunctionsScopePtr &c, const std::string &v)
{
	c->setReturnVar(c->newScriptVar(v));
}