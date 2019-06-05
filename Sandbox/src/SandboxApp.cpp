#include <Brioche.h>

class ExampleLayer : public Brioche::Layer
{
public:
	ExampleLayer()
		: Layer("Examle")
	{
	}

	void OnUpdate() override
	{
		BR_INFO("ExampleLayer::Update");
	}

	void OnEvent(Brioche::Event& event) override
	{
		BR_TRACE("{0}", event);
	}
};

class Sandbox : public Brioche::Application
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

Brioche::Application* Brioche::CreateApplication()
{
	return new Sandbox();
}
