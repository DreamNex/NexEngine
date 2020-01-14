 workspace "Nex"
 architecture "x64"
 startproject "SandBox"

 configurations
 {
  "Debug",
  "Release",
  "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Inlucde directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Nex/vendor/GLFW/include"
IncludeDir["Glad"] = "Nex/vendor/Glad/include"
IncludeDir["ImGui"] = "Nex/vendor/imgui"



group "Dependencies"
	include "Nex/vendor/GLFW"
	include "Nex/vendor/Glad"
	include "Nex/vendor/imgui"

group ""

 project "Nex"
 location "Nex"
 kind "SharedLib"
 language "C++"
 staticruntime "off"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 pchheader "PreH.h"
 pchsource "Nex/Src/PreH.cpp"

 files
 {
  "%{prj.name}/Src/**.h",
  "%{prj.name}/Src/**.cpp"
 }

 includedirs
 {
  "%{prj.name}/Src",
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
   "NX_PLATFORM_WINDOWS",
   "NX_BUILD_DLL",
   "GLFW_INCLUDE_NONE"
  }

  postbuildcommands
  {
   ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
  }

 filter "configurations:Debug"
  defines "NX_DEBUG"
  runtime "Debug"
  symbols "On"

 filter "configurations:Release"
  defines "NX_RELEASE"
  runtime "Release"
  optimize "On"

 filter "configurations:Dist"
  defines "NX_DIST"
  runtime "Release"
  optimize "On"

project "SandBox"
 location "SandBox"
 kind "ConsoleApp"
 language "C++"
 staticruntime "off"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 files
 {
  "%{prj.name}/Src/**.h",
  "%{prj.name}/Src/**.cpp"
 }

 includedirs
 {
  "Nex/vendor/spdlog/include",
  "Nex/Src"
 }

 links
 {
  "Nex"
 }

 filter "system:windows"
  cppdialect "C++17"
  systemversion "latest"

  defines
  {
   "NX_PLATFORM_WINDOWS"
  }

 filter "configurations:Debug"
  defines "NX_DEBUG"
  runtime "Debug"
  symbols "On"

 filter "configurations:Release"
  defines "NX_RELEASE"
  runtime "Release"
  optimize "On"

 filter "configurations:Dist"
  defines "NX_DIST"
  runtime "Release"
  optimize "On"