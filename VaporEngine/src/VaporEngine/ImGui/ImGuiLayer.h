#pragma once

#include "VaporEngine/Layer.h"
#include <VaporEngine\Events\MouseEvent.h>
#include <VaporEngine\Events\KeyEvent.h>
#include <VaporEngine\Events\ApplicationEvent.h>

namespace VaporEngine 
{
	class VAPORENGINE_API ImGuiLayer : public Layer 
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void Detach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		float m_Time = 0;

		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
	};
}