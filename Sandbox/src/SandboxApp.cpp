#include <Brioche.h>

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>''
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 camera(float Translate, glm::vec2 const & Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

class ExampleLayer : public Brioche::Layer
{
public:
	ExampleLayer()
		: Layer("Examle")
	{
		auto cam = camera(5.0f, { 0.5f, 0.5f });
	}

	void OnUpdate() override
	{
		//BR_INFO("ExampleLayer::Update");

		if (Brioche::Input::IsKeyPressed(BR_KEY_TAB))
			BR_TRACE("Tab has been pressed!");
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
		PushOverlay(new Brioche::ImGuiLayer());
	}

	~Sandbox()
	{
	
	}

};

Brioche::Application* Brioche::CreateApplication()
{
	return new Sandbox();
}
