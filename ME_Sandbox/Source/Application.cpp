#include <ME.h>

int main(int argc, char* args[])
{
	using namespace ME;

	Engine::Init("Sandbox", 1920, 1080);

	Entity entity1 = Engine::AddEntity();
	entity1.AddComponent<CircleCollider>().SetRadius(10);
	entity1.GetComponent<Transform>().SetPosition({ 10, 0 });

	Entity entity2 = Engine::AddEntity();
	entity2.AddComponent<CircleCollider>().SetRadius(10);
	entity2.GetComponent<Transform>().SetPosition({ -10, 0 });

	return 0;
}

