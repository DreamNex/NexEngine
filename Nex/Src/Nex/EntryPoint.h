#pragma once

#ifdef NX_PLATFORM_WINDOWS

extern Nex::Application* Nex::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Nex::CreateApplication();
	app->Run();
	delete app;
}
#endif
