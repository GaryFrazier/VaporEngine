workspace "VaporEngine"
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
IncludeDir["GLFW"] = "VaporEngine/vendor/GLFW/include"

include "VaporEngine/vendor/GLFW"

project "VaporEngine"
    location "VaporEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "vepch.h"
    pchsource "VaporEngine/src/vepch.cpp"

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
        systemversion "10.0.18362.0"

        defines
        {
            "VE_BUILD_DLL",
            "VE_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "VE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "VE_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "VE_DIST"
        symbols "On"

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
        "VaporEngine/vendor/spdlog/include",
        "VaporEngine/src"
    }

    links
    {
        "VaporEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "VE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "VE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "VE_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "VE_DIST"
        symbols "On"
