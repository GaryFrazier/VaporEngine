workspace "VaporEngine"
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
IncludeDir["GLFW"] = "VaporEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "VaporEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "VaporEngine/vendor/imgui"

group "Dependencies"
    include "VaporEngine/vendor/GLFW"
    include "VaporEngine/vendor/Glad"
    include "VaporEngine/vendor/imgui"

group ""

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
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "VE_BUILD_DLL",
            "VE_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines "VE_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "VE_RELEASE"
        runtime "Release"
        symbols "On"
    
    filter "configurations:Dist"
        defines "VE_DIST"
        runtime "Release"
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
        staticruntime "Off"
        systemversion "latest"

        defines
        {
            "VE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "VE_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "VE_RELEASE"
        runtime "Release"
        symbols "On"
    
    filter "configurations:Dist"
        defines "VE_DIST"
        runtime "Release"
        symbols "On"
