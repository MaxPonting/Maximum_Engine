#include <ME.h>


int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1280, 720);

	ME::Entity entity = engine.AddEntity();

	entity.AddComponent<ME::SpriteRenderer>();

	ME::SpriteRenderer renderer = entity.GetComponent<ME::SpriteRenderer>();
	

	
	engine.Run();

	return 0;
}
