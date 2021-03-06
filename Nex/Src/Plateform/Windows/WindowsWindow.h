#pragma once

#include "Nex/Window.h"
#include <GLFW/glfw3.h>

namespace Nex
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Attributes
		inline void SetEventCallback(const EventCallBackFn& callback) override{ m_Data.EventCallback = callback; }
		void SetVsync(bool enabled) override;
		bool isVsync() const override;

		inline virtual void* GetNativeWindow() const { return m_Window; }

	private: 
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool Vsync;

			EventCallBackFn EventCallback;
		};

		WindowData m_Data;


	};
}