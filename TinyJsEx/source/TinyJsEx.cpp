#include "stdafx.h"
#include "TinyJsEx.h"
#include "TinyJS.h"

static void fun_call_back(const CFunctionsScopePtr &c, void *userdata) 
{
	CallFunction *pFun = (CallFunction*)userdata;
	pFun->call(c);
}


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
CTinyJsEx::CTinyJsEx()
{
	m_tiny_js_ptr = new CTinyJS();
}

CTinyJsEx::~CTinyJsEx()
{
	for (auto it=m_funList.begin(); it!=m_funList.end(); ++it)
	{
		delete (*it);
	}

	delete m_tiny_js_ptr;
}

void CTinyJsEx::Execute(const char *Code, const std::string &File/*=""*/, int Line/*=0*/, int Column/*=0*/)
{
	m_tiny_js_ptr->execute(Code, File, Line, Column);
}

std::string CTinyJsEx::Evaluate(const char *code, const std::string &File/*=""*/, int Line/*=0*/, int Column/*=0*/)
{
	return m_tiny_js_ptr->evaluate(code, File, Line, Column);
}

bool CTinyJsEx::__AddFun(const std::string &str, CallFunction *fun_ptr)
{
	m_funList.push_back(fun_ptr);
	std::string sFuncDesc = "function ";
	sFuncDesc += str;
	sFuncDesc += fun_ptr->func_params();
	return m_tiny_js_ptr->addNative(sFuncDesc, fun_call_back, fun_ptr);
}

void CTinyJsEx::AddVar(const std::string &name, const int &var)
{
	m_tiny_js_ptr->getRoot()->addChild(name, m_tiny_js_ptr->newScriptVar(var));
}

void CTinyJsEx::AddVar(const std::string &name, const double &var)
{
	m_tiny_js_ptr->getRoot()->addChild(name, m_tiny_js_ptr->newScriptVar(var));
}

void CTinyJsEx::AddVar(const std::string &name, const std::string &var)
{
	m_tiny_js_ptr->getRoot()->addChild(name, m_tiny_js_ptr->newScriptVar(var));
}

bool CTinyJsEx::IsExpTrue(const std::string &exp)
{
//	X
// 	CScriptVarPtr var = m_tiny_js_ptr->newScriptVar(exp);
// 	return var->toBoolean();

	std::string s_exp = "result = " + exp;
	Execute(s_exp.c_str());
	return m_tiny_js_ptr->getRoot()->findChild("result")->toBoolean();
}
