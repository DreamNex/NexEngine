#include <Nex.h>

class ExampleLayer : public Nex::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
		
	}

	void OnUpdate() override
	{
		NX_INFO("Examlelayer::Update");

	}

	void OnEvent(Nex::Event& event) override
	{
		NX_TRACE("{0}", event);
	}
};

class SandBox : public Nex::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Nex::ImGuiLayer());
	}
	~SandBox()
	{

	}
};

Nex::Application* Nex::CreateApplication()
{
	return new SandBox();
}