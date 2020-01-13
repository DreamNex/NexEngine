#pragma once
#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Nex/Events/Event.h"
#include "Nex/Events/ApplicationEvent.h"

namespace Nex
{
	class NEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_isRunning = true;
		LayerStack m_LayerStack;
	};

	//To be define in client
	Application* CreateApplication();
}
