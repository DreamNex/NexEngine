#include <Nex.h>

class SandBox : public Nex::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

Nex::Application* Nex::CreateApplication()
{
	return new SandBox();
}