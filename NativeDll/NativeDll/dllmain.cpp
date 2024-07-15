#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
// __declspec(dllexport) is a Microsoft-specific keyword that exports a function from a DLL.
#define DLLExport __declspec (dllexport)
#else
// __attribute__((visibility("default"))) is a GCC-specific keyword that exports a function from a shared library.
#define DLLExport __attribute__((visibility("default")))
#endif

extern "C"
{
	DLLExport int IsItWorking()
	{
		return 1;
	}
	DLLExport const char* HelloWorld()
	{
		return "Hello, world!";
	}
}
