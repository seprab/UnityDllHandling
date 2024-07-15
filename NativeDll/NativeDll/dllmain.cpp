#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "IUnityInterface.h"
#include "IUnityProfiler.h"
#include "IUnityLog.h"

#ifdef _WIN32
// __declspec(dllexport) is a Microsoft-specific keyword that exports a function from a DLL.
#define DLLExport __declspec (dllexport)
#else
// __attribute__((visibility("default"))) is a GCC-specific keyword that exports a function from a shared library.
#define DLLExport __attribute__((visibility("default")))
#endif

static IUnityProfiler* s_UnityProfiler = NULL;
static IUnityInterfaces* s_UnityInterfaces = NULL;
static const UnityProfilerMarkerDesc* s_MyPluginMarker = NULL;
static bool s_IsDevelopmentBuild = false;

extern "C"
{
	DLLExport int IsItWorking()
	{
		UNITY_LOG(s_UnityInterfaces->Get<IUnityLog>(), "IsItWorking Method called.");
		return 1;
	}
	DLLExport const char* HelloWorld()
	{
		UNITY_LOG(s_UnityInterfaces->Get<IUnityLog>(), "HelloWorld Method called.");
		return "Hello, world!";
	}
	DLLExport void MyPluginWork()
	{
		if (s_IsDevelopmentBuild)
			s_UnityProfiler->BeginSample(s_MyPluginMarker);

		UNITY_LOG(s_UnityInterfaces->Get<IUnityLog>(), "MyPluginWork Method called.");

		if (s_IsDevelopmentBuild)
			s_UnityProfiler->EndSample(s_MyPluginMarker);
	}
	void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginLoad(IUnityInterfaces* unityInterfaces)
	{
		s_UnityInterfaces = unityInterfaces;
		s_UnityProfiler = s_UnityInterfaces->Get<IUnityProfiler>();
		if (s_UnityProfiler == NULL)
		{
			UNITY_LOG_ERROR(s_UnityInterfaces->Get<IUnityLog>(), "Failed to get IUnityProfiler interface.");
			return;
		}
		UNITY_LOG(s_UnityInterfaces->Get<IUnityLog>(), "UnityPluginLoad Method called.");
		s_IsDevelopmentBuild = s_UnityProfiler->IsAvailable() != 0;
		s_UnityProfiler->CreateMarker(&s_MyPluginMarker, "MyPluginMethod", kUnityProfilerCategoryOther, kUnityProfilerMarkerFlagDefault, 0);
	}
	void UNITY_INTERFACE_EXPORT UNITY_INTERFACE_API UnityPluginUnload()
	{
		UNITY_LOG(s_UnityInterfaces->Get<IUnityLog>(), "UnityPluginUnload Method called.");
		if (s_UnityProfiler != NULL)
		{
			s_UnityProfiler = NULL;
			UNITY_LOG(s_UnityInterfaces->Get<IUnityLog>(), "Failed to get IUnityProfiler interface.");
		}
	}
}
