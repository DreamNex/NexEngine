#include "PreH.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Nex
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		
		while (m_isRunning)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Window->OnUpdate();
		}
	}
}
