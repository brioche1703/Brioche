#include <Brioche.h>

#include "imgui/imgui.h"

class ExampleLayer : public Brioche::Layer
{
public:
	ExampleLayer()
		: Layer("Examle")
	{
	}

	void OnUpdate() override
	{
		//BR_INFO("ExampleLayer::Update");

		if (Brioche::Input::IsKeyPressed(BR_KEY_TAB))
			BR_TRACE("Tab has been pressed!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}

	void OnEvent(Brioche::Event& event) override
	{
		//BR_TRACE("{0}", event);
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
