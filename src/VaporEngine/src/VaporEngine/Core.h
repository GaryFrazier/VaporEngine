#pragma once

#ifdef VE_PLATFORM_WINDOWS
	#ifdef VE_BUILD_DLL
		#define VAPORENGINE_API __declspec(dllexport)
	#else
		#define VAPORENGINE_API __declspec(dllimport)
	#endif
#else
	#error Vapor Engine only supports Windows at this time
#endif