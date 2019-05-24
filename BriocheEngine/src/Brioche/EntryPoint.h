#pragma once

#ifdef BR_PLATFORM_WINDOWS

extern Brioche::Application* Brioche::CreateApplication();

int main(int argc, char** argv)
{
	printf("Brioche Engine");
	auto app = Brioche::CreateApplication();
	app->Run();
	delete app;
}

#endif
