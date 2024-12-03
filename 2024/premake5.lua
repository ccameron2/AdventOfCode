workspace "AoC2024"
    platforms "x64"
    architecture "x64"
    startproject "AoC2024"
    dpiawareness "HighPerMonitor"
    
    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AoC2024"
    location "AoC2024"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"
    
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
    }
                
    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"
        debugdir ("bin/" .. outputdir .. "/%{prj.name}")

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
        debugdir("bin/" .. outputdir .. "/%{prj.name}")