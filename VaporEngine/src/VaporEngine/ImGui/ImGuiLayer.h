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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0;
	};
}