#pragma once
#include "Core.h"
namespace Nex
{
	class NEX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be define in client
	Application* CreateApplication();
}
