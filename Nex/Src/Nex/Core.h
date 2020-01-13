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

#ifdef NX_ENABLE_ASSERTS
#define NX_ASSERT(x, ...) {if(!(x)){NX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#define NX_CORE_ASSERT(x, ...) {if(!(x)) { NX_CORE_ERROR("Assetion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
#define NX_ASSERT(x,...)
#define NX_CORE_ASSERT(x, ...)

#endif

#define BIT(x) (1 << x)