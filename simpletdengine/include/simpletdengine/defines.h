#pragma once

#ifdef _WIN32
#define SIMPLETDENGINE_DLL_EXPORT __declspec(dllexport)
#define SIMPLETDENGINE_DLL_IMPORT __declspec(dllimport)
#else
#define SIMPLETDENGINE_DLL_EXPORT
#define SIMPLETDENGINE_DLL_IMPORT
#ifdef SIMPLETDENGINE_BUILD_DLL
#error Unsupported platform for dynamic linkking
#endif
#endif

#ifdef SIMPLETDENGINE_BUILD_DLL
#define SIMPLETDENGINE_API SIMPLETDENGINE_DLL_EXPORT
#elif defined(SIMPLETDENGINE_USE_DLL)
#define SIMPLETDENGINE_API SIMPLETDENGINE_DLL_IMPORT
#else
#define SIMPLETDENGINE_API
#endif