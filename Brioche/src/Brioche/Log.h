#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Brioche {

	class BRIOCHE_API Log
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

// Core log macros
#define BR_CORE_TRACE(...)   ::Brioche::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BR_CORE_INFO(...)    ::Brioche::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BR_CORE_WARN(...)    ::Brioche::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BR_CORE_ERROR(...)   ::Brioche::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BR_CORE_FATAL(...)   ::Brioche::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log
#define BR_TRACE(...)   ::Brioche::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BR_INFO(...)    ::Brioche::Log::GetClientLogger()->info(__VA_ARGS__)
#define BR_WARN(...)    ::Brioche::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BR_ERROR(...)   ::Brioche::Log::GetClientLogger()->error(__VA_ARGS__)
#define BR_FATAL(...)   ::Brioche::Log::GetClientLogger()->fatal(__VA_ARGS__)
