#pragma once

#include "VaporEngine/Layer.h"

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
	};
}