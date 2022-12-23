#include <ME.h>

class Controller : public ME::ScriptComponent
{
	using ScriptComponent::ScriptComponent;
	
	ME::Transform transform;

	const float moveSpeed = 400;
	const float zoomSpeed = 1;
	const float rotationSpeed = 50;

	void Start()
	{
		transform = GetEntity().GetComponent<ME::Transform>();
	}

	void Update()
	{
		// Movement
		if (ME::Engine::GetKey(ME_KEYCODE_W))
		{
			transform.SetPosition({ transform.GetPosition().X, transform.GetPosition().Y + moveSpeed * ME::Engine::GetTime().DeltaTime });
		}
		if (ME::Engine::GetKey(ME_KEYCODE_S))
		{
			transform.SetPosition({ transform.GetPosition().X, transform.GetPosition().Y - moveSpeed * ME::Engine::GetTime().DeltaTime });
		}
		if (ME::Engine::GetKey(ME_KEYCODE_D))
		{
			transform.SetPosition({ transform.GetPosition().X + moveSpeed * ME::Engine::GetTime().DeltaTime, transform.GetPosition().Y });
		}
		if (ME::Engine::GetKey(ME_KEYCODE_A))
		{
			transform.SetPosition({ transform.GetPosition().X - moveSpeed * ME::Engine::GetTime().DeltaTime, transform.GetPosition().Y  });
		}

		// Zoom
		if (ME::Engine::GetKey(ME_KEYCODE_UP))
		{
			transform.SetScale({ transform.GetScale().X - zoomSpeed * ME::Engine::GetTime().DeltaTime, transform.GetScale().Y - zoomSpeed * ME::Engine::GetTime().DeltaTime });
		}
		if (ME::Engine::GetKey(ME_KEYCODE_DOWN))
		{
			transform.SetScale({ transform.GetScale().X + zoomSpeed * ME::Engine::GetTime().DeltaTime, transform.GetScale().Y + zoomSpeed * ME::Engine::GetTime().DeltaTime });
		}

		// Rotate
		if (ME::Engine::GetKey(ME_KEYCODE_LEFT))
		{
			transform.SetRotation(transform.GetRotation() - rotationSpeed * ME::Engine::GetTime().DeltaTime);
		}
		if (ME::Engine::GetKey(ME_KEYCODE_RIGHT))
		{
			transform.SetRotation(transform.GetRotation() + rotationSpeed * ME::Engine::GetTime().DeltaTime);
		}

	}
};

int main(int argc, char* args[])
{
	ME::Engine::Init("Sandbox", 1920, 1080);

	ME::Texture texture = ME::Engine::AddTexture("../Assets/PNGs/Sword.png");

	ME::Engine::GetMainCamera().GetEntity().AddScript<Controller>();

	ME::SpriteRenderer spriteRenderer = ME::Engine::AddEntity().AddComponent<ME::SpriteRenderer>();
	spriteRenderer.SetTexture(texture);

	ME::Transform transform = ME::Engine::AddEntity().GetComponent<ME::Transform>();
	transform.AddComponent<ME::SpriteRenderer>();
	transform.SetPosition({ 300, 300 });
	transform.SetScale({ 200, 200 });

	ME::Engine::Start();

	return 0;
}
