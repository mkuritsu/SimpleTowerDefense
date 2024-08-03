#pragma once

#ifdef _WIN32
#define SIMPLETDENGINE_EXPORT_SYMBOL __declspec(dllexport)
#define SIMPLETDENGINE_IMPORT_SYMBOL __declspec(dllimport)
#else
#define SIMPLETDENGINE_EXPORT_SYMBOL
#define SIMPLETDENGINE_IMPORT_SYMBOL
#ifdef SIMPLETDENGINE_DLL_EXPORT
#error Unsupported platform for dynamic linkking
#endif
#endif

#if defined(SIMPLETDENGINE_DLL_EXPORT)
#define SIMPLETDENGINE_API SIMPLETDENGINE_EXPORT_SYMBOL
#elif defined(SIMPLETDENGINE_DLL_IMPORT)
#define SIMPLETDENGINE_API SIMPLETDENGINE_IMPORT_SYMBOL
#else
#define SIMPLETDENGINE_API
#endif