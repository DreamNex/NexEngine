#pragma once

#ifdef NX_PLATFORM_WINDOWS

extern Nex::Application* Nex::CreateApplication();

int main(int argc, char** argv)
{

	Nex::Log::Init();
	NX_CORE_WARN("Initialized Log");
	int a = 1;
	NX_INFO("App Start Version: {0}", a);

	auto app = Nex::CreateApplication();
	app->Run();
	delete app;
}
#endif
