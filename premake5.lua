workspace "Brioche"
	architecture "x64"
	startproject "Sandbox"

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
IncludeDir["Glad"] = "Brioche/vendor/Glad/include"
IncludeDir["ImGui"] = "Brioche/vendor/imgui"

include "Brioche/vendor/GLFW"
include "Brioche/vendor/Glad"
include "Brioche/vendor/imgui"

project "Brioche"
	location "Brioche"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS",
			"BR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		systemversion "latest"

		defines
		{
			"BR_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "BR_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "BR_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "BR_DIST"
		runtime "Release"
		optimize "On"
