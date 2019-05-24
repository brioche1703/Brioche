#pragma once

#include "Core.h"

namespace Brioche {

	class BRIOCHE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}