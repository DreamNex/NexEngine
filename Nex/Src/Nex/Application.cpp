#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Nex
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowRezieEvent e(1280, 720);
		NX_TRACE(e);
		while (true);
	}
}
