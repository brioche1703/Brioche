#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Brioche::Application* Brioche::CreateApplication();

int main(int argc, char** argv)
{

	Brioche::Log::Init();
	BR_CORE_WARN("Initialized Log!");
	int a = 5;
	BR_INFO("Hello! Var={0}", a);

	auto app = Brioche::CreateApplication();
	app->Run();
	delete app;
}

#endif
