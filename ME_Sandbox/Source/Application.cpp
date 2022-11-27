#include <ME.h>

int main(int argc, char* args[])
{
	/* Init */
	ME::Manager::Init();

	/* Create Instance of Engine */
	ME::Engine<1000, 1000, 1000> engine = ME::Engine<1000, 1000, 1000>("Sandbox", 1280, 720);

	
	/* Create an entity with a square rendering sprite */
//	const ME::Entity& square = engine.AddEntity();
//	square.Transform.Position = Vector2(400, 400);
//	const ME::SpriteRenderer renderer = square.AddComponent<ME::SpriteRenderer>();
//	renderer.SetSprite(ME::Rectangle(100, 80)));
//
//	/* Create Sprite with filePath */
//	const ME::Sprite& sprite = engine.AddSprite("filePath");
//
//	/* Create an entity with a texture rendering sprite */
//	const ME::Entity& texturedEntity = engine.AddEntity();
//	texturedEntity.Transform.Position = Vector2(700, 400);
//	const ME::SpriteRenderer renderer2 = texturedEntity.AddComponent<ME::SpriteRenderer>();
//	renderer.SetSprite(texture)
	

	/* Call Run */
	engine.Run();

	return 0;
}
