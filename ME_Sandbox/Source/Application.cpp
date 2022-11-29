#include <ME.h>

int main(int argc, char* args[])
{
	/* Init */
	ME::Manager::Init();

	/* Create Instance of Engine */
	ME::Engine<1000, 1000, 1000> engine = ME::Engine<1000, 1000, 1000>("Sandbox", 1280, 720);
	
	/* Create an entity with a square rendering sprite */
//	const ME::Entity& entity = engine.AddEntity();
//	entity.Transform.Position = Vector2(400, 400);
//	const ME::SpriteRenderer renderer = square.AddComponent<ME::SpriteRenderer>();
//  const ME::Texture& rect = engine.AddRectangle(100, 100);
//	renderer.SetTexture(rect);
//
//	/* Create Texture with filePath */
//	const ME::Sprite& sprite = engine.AddTexture("filePath");
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
