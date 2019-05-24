#pragma once

#ifdef BR_PLATFORM_WINDOWS
	#ifdef BR_BUILD_DLL
		#define BRIOCHE_API __declspec(dllexport)
	#else
		#define BRIOCHE_API __declspec(dllimport)
	#endif
#else
	#error Brioche only support Windows!
#endif