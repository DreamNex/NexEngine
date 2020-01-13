#pragma once

#include "PreH.h"
#include "Nex/Core.h"
#include "Nex/Events/Event.h"

namespace Nex
{
	struct WindowProps
	{
		std::string Title;
		unsigned int W_Width;
		unsigned int W_Height;

		WindowProps(const std::string& title = "Nex Engine", unsigned int width = 1280, unsigned int height = 720) :
			Title(title), W_Width(width), W_Height(height)
		{

		}
	};

	// Interface 
	class NEX_API Window
	{
	public:

		using EventCallBackFn = std::function<void(Event&)>;
		virtual ~Window(){}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//Attributes for window
		virtual void SetEventCallback(const EventCallBackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool isVsync() const = 0;
		static Window* Create(const WindowProps& props = WindowProps());

	};
}
