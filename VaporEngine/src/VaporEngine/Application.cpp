#include "vepch.h"

#include "Application.h"
#include "VaporEngine/Events/ApplicationEvent.h"
#include "VaporEngine/Log.h"

namespace VaporEngine
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			VE_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			VE_TRACE(e);
		}
		

		while (true);
	}
}