workspace "GameEngine"
 architecture "x64"

 configurations
 {
  "Debug",
  "Release",
  "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.architecture}"


 IncludeDir = {}
 IncludeDir["GLFW"] = "GameEngine/vendor/GLFW/include"

 include "GameEngine/vendor/GLFW"


 project "GameEngine"
 location "GameEngine"
 kind "ConsoleApp"
 language "C++"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 files
 {
  "%{prj.name}/src/**.h",
  "%{prj.name}/src/**.cpp",
  "%{prj.name}/src/**.c",
  "%{prj.name}/src/**.txt"
 }


 includedirs
 {
  -- "%{prj.name}/vendor/spdlog/include"
     "%{prj.name}/vendor/GLAD",

  -- podría usar "%{IncludeDir.GLFW}"
     "%{prj.name}/vendor/GLFW/include"
 }

 filter "system:windows"
  cppdialect "C++17"
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "HZ_PLATFORM_WINDOWS",
   "HZ_BUILD_DLL"
  }


  links{
     "opengl32.lib",
     "GLFW"
  }
 

 filter "configurations:Debug"
  defines "HZ_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "HZ_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "HZ_DIST"
  optimize "On"