#include <ME.h>

class CameraController : public ME::ScriptComponent
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

class Controller : public ME::ScriptComponent
{
	using ScriptComponent::ScriptComponent;

	ME::Transform transform;

	const float moveSpeed = 400;

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
			transform.SetPosition({ transform.GetPosition().X - moveSpeed * ME::Engine::GetTime().DeltaTime, transform.GetPosition().Y });
		}
	}	

	void OnCollision(ME::Collider collider)
	{
		//std::cout << "Collison\n";
	}
};


int main(int argc, char* args[])
{
	ME::Engine::Init("Sandbox", 1920, 1080);

	//ME::Engine::GetMainCamera().GetEntity().AddScript<CameraController>();

	ME::SpriteRenderer SpriteRenderer = ME::Engine::AddEntity().AddComponent<ME::SpriteRenderer>();	
	SpriteRenderer.AddScript<Controller>();
	ME::RectangleCollider collider = SpriteRenderer.AddComponent<ME::RectangleCollider>();
	collider.SetHeight(200); collider.SetWidth(200);
	ME::Transform transform = SpriteRenderer.GetComponent<ME::Transform>();
	transform.SetPosition({ 400, 0 });
	transform.SetScale({ 200, 200 });
	
	
	ME::CircleRenderer circleRenderer2 = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circleRenderer2.SetRadius(100);
	circleRenderer2.AddComponent<ME::CircleCollider>().SetRadius(100);
	
	ME::SpriteRenderer spriteRenderer2 = ME::Engine::AddEntity().AddComponent<ME::SpriteRenderer>();
	spriteRenderer2.GetComponent<ME::Transform>().SetScale({ 200, 200 });
	spriteRenderer2.GetComponent<ME::Transform>().SetPosition({ -250, 0 });
	ME::RectangleCollider collider2 = spriteRenderer2.AddComponent<ME::RectangleCollider>();
	collider2.SetHeight(200); collider2.SetWidth(200);
	
	

	ME::Engine::Start();

	return 0;
}
