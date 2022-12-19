#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1920, 1080);

	ME::Entity entity = engine.AddEntity();
	
	ME::Transform transform = entity.GetComponent<ME::Transform>();
	transform.SetPosition(ME::Vector2i(100, 100));

	ME::CircleRenderer circleRenderer = entity.AddComponent<ME::CircleRenderer>();
	circleRenderer.SetRadius(400);
	
	engine.Run();

	return 0;
}
