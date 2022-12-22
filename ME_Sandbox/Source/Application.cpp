#include <ME.h>

class Controller : public ME::ScriptComponent
{
	using ScriptComponent::ScriptComponent;
	
	ME::Transform transform;

	void Start()
	{
		transform = GetEntity().GetComponent<ME::Transform>();
	}

	void Update()
	{
		transform.SetPosition(ME::Vector2f(transform.GetPosition().X, 400));
		transform.SetRotation(transform.GetRotation() + 1 * ME::Engine::GetTime().DeltaTime);
		transform.SetScale(ME::Vector2f(transform.GetScale().X + 0.01 * ME::Engine::GetTime().DeltaTime, 1));
	}
};

int main(int argc, char* args[])
{
	ME::Engine::Init("Sandbox", 1920, 1080);

    ME::Font font = ME::Engine::AddFont("../Assets/Fonts/PixelFJVerdana12pt.ttf");

	ME::Texture texture = ME::Engine::AddTexture("../Assets/PNGs/Sword.png");

	ME::Transform transform = ME::Engine::AddEntity().GetComponent<ME::Transform>();
	transform.SetPosition(ME::Vector2i(700, 500));
	transform.SetRotation(60);

	ME::TextRenderer textRenderer = transform.GetEntity().AddComponent<ME::TextRenderer>();
	textRenderer.SetText("Hello World");
	textRenderer.SetFont(font);
	textRenderer.SetFontSize(36);
	textRenderer.SetColour(ME::RGBA(255, 0, 255, 255));
	transform.GetEntity().AddScript<Controller>();

	ME::Engine::Start();

	return 0;
}
