#pragma once
#include "Core.h"

#ifdef VE_PLATFORM_WINDOWS

	extern VaporEngine::Application* VaporEngine::CreateApplication();

	int main(int argc, char** argv)
	{
		printf("Welcome to V A P O R E N G I N E\n");
		auto app = VaporEngine::CreateApplication();
		app->Run();
		delete app;
	}
#endif