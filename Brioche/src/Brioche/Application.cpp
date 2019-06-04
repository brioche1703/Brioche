#include "Application.h"

#include "Brioche/Events/ApplicationEvent.h"
#include "Brioche/Log.h"

namespace Brioche {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		BR_TRACE(e);

		while (true);
	}

}