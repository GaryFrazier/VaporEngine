#include<VaporEngine.h>

class ExampleLayer : public VaporEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{

	}

	void OnEvent(VaporEngine::Event& event) override
	{
		if (event.GetEventType() == VaporEngine::EventType::KeyPressed)
		{
			VaporEngine::KeyPressedEvent& e = (VaporEngine::KeyPressedEvent&)event;
			VE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public VaporEngine::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new VaporEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

VaporEngine::Application* VaporEngine::CreateApplication()
{
	return new Sandbox();
}
