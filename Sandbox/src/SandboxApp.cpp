#include <Brioche.h>

class Sandbox : public Brioche::Application
{
public:
	Sandbox()
	{
	
	}

	~Sandbox()
	{
	
	}

};

Brioche::Application* Brioche::CreateApplication()
{
	return new Sandbox();
}
