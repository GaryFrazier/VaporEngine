#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace VaporEngine 
{
	class VAPORENGINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

#define VE_CORE_FATAL(...) ::VaporEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define VE_CORE_ERROR(...) ::VaporEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VE_CORE_WARN(...) ::VaporEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VE_CORE_INFO(...) ::VaporEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VE_CORE_TRACE(...) ::VaporEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define VE_FATAL(...) ::VaporEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define VE_ERROR(...) ::VaporEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define VE_WARN(...) ::VaporEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VE_INFO(...) ::VaporEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define VE_TRACE(...) ::VaporEngine::Log::GetClientLogger()->trace(__VA_ARGS__)