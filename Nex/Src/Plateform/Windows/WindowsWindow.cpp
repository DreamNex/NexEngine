#include "PreH.h"
#include "WindowsWindow.h"

namespace Nex
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.W_Width;
		m_Data.Height = props.W_Height;

		NX_CORE_INFO("Creating window {0} {1}, {2}", props.Title, props.W_Width, props.W_Height);
		
		if (!s_GLFWInitialized)
		{
			
			int success = glfwInit();
			NX_CORE_ASSERT(success, "Could not init GLFW");
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)props.W_Width, (int)props.W_Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVsync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVsync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.Vsync = enabled;
	}

	bool WindowsWindow::isVsync() const
	{
		return m_Data.Vsync;
	}
}

