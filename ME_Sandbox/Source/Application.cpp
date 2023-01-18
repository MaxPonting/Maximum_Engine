#include <ME.h>

class Script : public ME::ScriptComponent
{
	using ScriptComponent::ScriptComponent;
};

int main(int argc, char* args[])
{
	using namespace ME;

	Engine::Init("Sandbox", 1920, 1080);

	Entity entity = ME::Engine::AddEntity();
	Script* script = entity.AddScript<Script>();

	if (script->HasScript<Script>())
		std::cout << "True\n";

	entity.DestroyScript<Script>();

	if (!entity.HasScript<Script>())
		std::cout << "True\n";
	
	Engine::Start();

	return 0;
}

