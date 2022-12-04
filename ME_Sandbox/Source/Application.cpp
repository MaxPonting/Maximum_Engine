#include <ME.h>


int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1280, 720);

	ME::Entity entity = engine.AddEntity();

	entity.AddComponent<ME::SpriteRenderer>();

	ME::Transform transform = entity.GetComponent<ME::Transform>();
	ME::SpriteRenderer renderer = entity.GetComponent<ME::SpriteRenderer>();

	transform.SetScale(ME::Vector2(400, 400));
	transform.SetPosition(ME::Vector2(200, 200));
	transform.SetRotation(30);

	renderer.SetColour(ME::RGBA(255, 0, 0, 255));
	
	engine.Run();

	return 0;
}
