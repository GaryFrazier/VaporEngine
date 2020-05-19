#pragma once
#include "Core.h"
#include "Window.h"
#include "VaporEngine/Events/ApplicationEvent.h"
#include "VaporEngine/Events/Event.h"
#include "VaporEngine/LayerStack.h"

namespace VaporEngine 
{
	class VAPORENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


