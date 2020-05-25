#pragma once
#include "Core.h"
#include "Window.h"
#include "VaporEngine/Events/ApplicationEvent.h"
#include "VaporEngine/Events/Event.h"
#include "VaporEngine/LayerStack.h"

#include "VaporEngine/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }
		static inline Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


