#include <ME.h>

int main(int argc, char* args[])
{
	using namespace ME;

	Engine::Init("Sandbox", 1920, 1080);

	Engine::GetMainCamera().GetComponent<Transform>().SetPosition({ 0, 0 });

	Entity entity = Engine::AddEntity();
	entity.AddComponent<SpriteRenderer>();
	entity.GetComponent<Transform>().SetScale({ 100, 100 });

	Engine::Start();

	return 0;
}

