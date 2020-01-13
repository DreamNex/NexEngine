#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Nex
{
	class NEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_isRunning = true;
	};

	//To be define in client
	Application* CreateApplication();
}
