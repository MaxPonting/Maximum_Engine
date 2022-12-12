#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1280, 720);

	ME::Entity entity = engine.AddEntity();
	ME::Entity entity2 = engine.AddEntity();
	ME::Entity entity3 = engine.AddEntity();

	ME::Texture texture = engine.AddTextureWithFilePath("../Assets/PNGs/Sword.png");
	ME::Texture texture2 = engine.AddTextureWithFilePath("../Assets/JPGs/Knight.jpg");

	ME::Transform transform = entity.GetComponent<ME::Transform>();
	ME::SpriteRenderer renderer = entity.AddComponent<ME::SpriteRenderer>();	
	transform.SetPosition(ME::Vector2(100, 400));
	renderer.SetTexture(texture);
	renderer.SetLayer(1);

	ME::Transform transform2 = entity2.GetComponent<ME::Transform>();
	ME::SpriteRenderer renderer2 = entity2.AddComponent<ME::SpriteRenderer>();
	transform2.SetPosition(ME::Vector2(0, 0));
	transform2.SetScale(ME::Vector2(20, 20));
	transform2.SetRotation(0);
	renderer2.SetTexture(texture2);
	renderer2.SetLayer(-1);

	ME::Transform transform3 = entity3.GetComponent<ME::Transform>();
	ME::CircleRenderer renderer3 = entity3.AddComponent<ME::CircleRenderer>();
	transform3.SetPosition(ME::Vector2(500, 50));
	transform3.SetScale(ME::Vector2(1, 1));
	renderer3.SetRadius(200);
	renderer3.SetColour(ME::RGBA(255, 0, 0, 255));
	
	engine.Run();

	return 0;
}
