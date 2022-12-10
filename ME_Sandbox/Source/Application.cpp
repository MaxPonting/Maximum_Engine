#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1280, 720);

	ME::Entity entity = engine.AddEntity();
	ME::Entity entity2 = engine.AddEntity();

	ME::Transform transform = entity.GetComponent<ME::Transform>();
	ME::SpriteRenderer renderer = entity.AddComponent<ME::SpriteRenderer>();
	transform.SetPosition(ME::Vector2(400, 400));
	transform.SetScale(ME::Vector2(100, 100));

	ME::Transform transform2 = entity2.GetComponent<ME::Transform>();
	ME::CircleRenderer renderer2 = entity2.AddComponent<ME::CircleRenderer>();
	transform2.SetPosition(ME::Vector2(600, 200));
	renderer2.SetRadius(100);
	
	engine.Run();

	return 0;
}
