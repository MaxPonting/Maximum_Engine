#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1280, 720);

	ME::Entity entity = engine.AddEntity();
	ME::Entity entity2 = engine.AddEntity();

	ME::Transform transform = entity.GetComponent<ME::Transform>();
	ME::SpriteRenderer renderer = entity.AddComponent<ME::SpriteRenderer>();
	ME::Texture texture = engine.AddTextureWithFilePath("../Dependencies/PNGs/Sword.png");
	transform.SetPosition(ME::Vector2(100, 400));
	transform.SetRotation(90);
	transform.SetScale(ME::Vector2(1, 1));
	renderer.SetTexture(texture);

	ME::Transform transform2 = entity2.GetComponent<ME::Transform>();
	ME::CircleRenderer renderer2 = entity2.AddComponent<ME::CircleRenderer>();
	transform2.SetPosition(ME::Vector2(500, 50));
	transform2.SetScale(ME::Vector2(1, 1));
	renderer2.SetRadius(200);
	renderer2.SetColour(ME::RGBA(255, 0, 0, 255));
	
	engine.Run();

	return 0;
}
