workspace "Brioche"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Brioche/vendor/GLFW/include"

include "Brioche/vendor/GLFW"

project "Brioche"
	location "Brioche"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "brpch.h"
	pchsource "Brioche/src/brpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS",
			"BR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "BR_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "BR_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Brioche/vendor/spdlog/include",
		"Brioche/src"
	}

	links
	{
		"Brioche"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "BR_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "BR_DIST"
		optimize "On"

