#pragma once
#include "Core.h"

namespace VaporEngine {
	class VAPORENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


