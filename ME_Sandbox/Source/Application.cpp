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
		
	}
};

int main(int argc, char* args[])
{
	ME::Engine::Init("Sandbox", 1920, 1080);

	ME::Texture texture = ME::Engine::AddTexture("../Assets/PNGs/Sword.png");

	ME::Transform transform = ME::Engine::AddEntity().GetComponent<ME::Transform>();
	ME::SpriteRenderer spriteRenderer = transform.GetEntity().AddComponent<ME::SpriteRenderer>();
	spriteRenderer.SetTexture(texture);

	ME::Engine::Start();

	return 0;
}
