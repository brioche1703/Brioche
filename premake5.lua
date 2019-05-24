workspace "Brioche"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

project "Brioche"
	location "Brioche"

	BR_PLATFORM_WINDOWS;BR_BUILD_DLL;_WINDLL
