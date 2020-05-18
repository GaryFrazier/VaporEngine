#include<VaporEngine.h>

class Sandbox : public VaporEngine::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

VaporEngine::Application* VaporEngine::CreateApplication()
{
	return new Sandbox();
}
