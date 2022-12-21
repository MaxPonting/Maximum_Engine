#include <ME.h>

class Controller : public ME::ScriptComponent
{
	using ScriptComponent::ScriptComponent;

	ME::Vector2f pos;

	void Update()
	{
		pos = ME::Vector2f(pos.X + 0.1, 400);
		GetEntity().GetComponent<ME::Transform>().SetPosition(pos);
	}
};

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1920, 1080);

    ME::Font font = engine.AddFont("../Assets/Fonts/PixelFJVerdana12pt.ttf");

	ME::Texture texture = engine.AddTexture("../Assets/PNGs/Sword.png");

	
	ME::Transform transform = engine.AddEntity().GetComponent<ME::Transform>();
	transform.SetPosition(ME::Vector2i(500, 500));
	transform.SetRotation(60);

	ME::TextRenderer textRenderer = transform.GetEntity().AddComponent<ME::TextRenderer>();
	textRenderer.SetText("Hello World");
	textRenderer.SetFont(font);
	textRenderer.SetFontSize(36);
	textRenderer.SetColour(ME::RGBA(255, 0, 255, 255));

	transform.GetEntity().AddScript<Controller>();

	engine.Run();

	return 0;
}
