#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1920, 1080);

    ME::Font font = engine.AddFont("../Assets/Fonts/PixelFJVerdana12pt.ttf");

	ME::Entity entity = engine.AddEntity();
	
	ME::Transform transform = entity.GetComponent<ME::Transform>();
	transform.SetPosition(ME::Vector2i(500, 500));

	ME::TextRenderer textRenderer = entity.AddComponent<ME::TextRenderer>();
	textRenderer.SetText("Hello World");
	textRenderer.SetFont(font);
	textRenderer.SetFontSize(36);
	textRenderer.SetColour(ME::RGBA(255, 0, 255, 255));
	
	engine.Run();

	return 0;
}
