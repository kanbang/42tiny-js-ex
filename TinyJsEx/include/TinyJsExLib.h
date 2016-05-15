#pragma once

#ifdef _BUILD_IN_TINY_JS_EX

#define TINY_JS_EX_API __declspec(dllexport)

#else

#define TINY_JS_EX_API __declspec(dllimport)

#ifdef _DEBUG
#pragma comment(lib, "..\\debug\\TinyJsEx.lib")
#else
#pragma comment(lib, "..\\release\\TinyJsEx.lib")
#endif // _DEBUG

#endif
