#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1920, 1080);

	ME::Entity entity = engine.AddEntity();

	ME::Texture texture = engine.AddTextureWithFilePath("../Assets/PNGs/Sword.png");
	
	ME::Transform transform = entity.GetComponent<ME::Transform>();
	ME::SpriteRenderer spriteRenderer = entity.AddComponent<ME::SpriteRenderer>();
	transform.SetPosition(ME::Vector2i(300, 700));
	spriteRenderer.SetTexture(texture);
	entity = transform.GetEntity();

	ME::CircleRenderer circleRenderer = entity.AddComponent<ME::CircleRenderer>();
	circleRenderer.SetRadius(100);
	transform.SetPosition(ME::Vector2i(300, 300));
	
	engine.Run();

	return 0;
}
