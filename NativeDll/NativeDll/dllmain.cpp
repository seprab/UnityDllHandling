#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define DLLExport __declspec (dllexport)

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
