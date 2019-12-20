#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Nex
{
	class NEX_API Log
	{

	public: 
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Engine log macros
#define NX_CORE_TRACE(...)   ::Nex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NX_CORE_INFO(...)    ::Nex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NX_CORE_WARN(...)    ::Nex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NX_CORE_ERROR(...)   ::Nex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NX_CORE_FATAL(...)   ::Nex::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Clien log macros
#define NX_TRACE(...)   ::Nex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NX_INFO(...)    ::Nex::Log::GetClientLogger()->info(__VA_ARGS__)
#define NX_WARN(...)    ::Nex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NX_ERROR(...)   ::Nex::Log::GetClientLogger()->error(__VA_ARGS__)
#define NX_FATAL(...)   ::Nex::Log::GetClientLogger()->fatal(__VA_ARGS__)