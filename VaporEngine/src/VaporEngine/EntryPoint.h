#pragma once
#include "Core.h"

#ifdef VE_PLATFORM_WINDOWS

	extern VaporEngine::Application* VaporEngine::CreateApplication();

	int main(int argc, char** argv)
	{
		VaporEngine::Log::Init();
		VE_CORE_INFO("Welcome to V A P O R E N G I N E");
		VE_INFO("Welcome to V A P O R W O R L D");

		auto app = VaporEngine::CreateApplication();
		app->Run();
		delete app;
	}
#endif