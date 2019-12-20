#pragma once

#ifdef NX_PLATFORM_WINDOWS
#ifdef NX_BUILD_DLL
#define NEX_API __declspec(dllexport)
#else
#define NEX_API __declspec(dllimport)
#endif
#else
#error Nex only supports Windows
#endif

#define BIT(x) (1 << x)