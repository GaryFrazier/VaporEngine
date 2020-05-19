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
		VE_INFO("ExampleLayer::Update");
	}

	void OnEvent(VaporEngine::Event& event) override
	{
		VE_TRACE("{0}", event);
	}
};


class Sandbox : public VaporEngine::Application 
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

VaporEngine::Application* VaporEngine::CreateApplication()
{
	return new Sandbox();
}
