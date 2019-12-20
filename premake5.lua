 workspace "Nex"
 architecture "x64"

 configurations
 {
  "Debug",
  "Release",
  "Dist"
 }

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 project "Nex"
 location "Nex"
 kind "SharedLib"
 language "C++"

 targetdir ("bin/" .. outputdir .. "/%{prj.name}")
 objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

 files
 {
  "%{prj.name}/Src/**.h",
  "%{prj.name}/Src/**.cpp"
 }

 includedirs
 {
  "%{prj.name}/Src",
  "%{prj.name}/vendor/spdlog/include"
 }

 filter "system:windows"
  cppdialect "C++17"
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "NX_PLATFORM_WINDOWS",
   "NX_BUILD_DLL"
  }

  postbuildcommands
  {
   ("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/SandBox")
  }

 filter "configurations:Debug"
  defines "NX_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "NX_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "NX_DIST"
  optimize "On"

project "SandBox"
 location "SandBox"
 kind "ConsoleApp"
 language "C++"

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
  staticruntime "On"
  systemversion "latest"

  defines
  {
   "NX_PLATFORM_WINDOWS"
  }

 filter "configurations:Debug"
  defines "NX_DEBUG"
  symbols "On"

 filter "configurations:Release"
  defines "NX_RELEASE"
  optimize "On"

 filter "configurations:Dist"
  defines "NX_DIST"
  optimize "On"