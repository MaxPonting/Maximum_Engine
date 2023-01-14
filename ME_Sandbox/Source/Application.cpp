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
			ME::Engine::DebugLog("Moved Left");
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
	const float rotationSpeed = 50;

	void Start()
	{
		transform = GetEntity().GetComponent<ME::Transform>();
	}

	void Update()
	{
		// Quit
		if (ME::Engine::GetKey(SDL_SCANCODE_ESCAPE))
		{
			ME::Engine::End();
		}
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

		if (ME::Engine::GetKey(ME_KEYCODE_LEFT))
		{
			
			transform.SetRotation(transform.GetRotation() - rotationSpeed * ME::Engine::GetTime().DeltaTime);
		}
		if (ME::Engine::GetKey(ME_KEYCODE_RIGHT))
		{
			transform.SetRotation(transform.GetRotation() + rotationSpeed * ME::Engine::GetTime().DeltaTime);
		}

		if (HasComponent<ME::PolygonRenderer>())  GetComponent<ME::PolygonRenderer>().SetColour({ 255, 255, 255, 255 });
		if (HasComponent<ME::SpriteRenderer>())  GetComponent<ME::SpriteRenderer>().SetColour({ 255, 255, 255, 255 });
	}	

	void OnCollision(ME::Collider collider)
	{
		if (HasComponent<ME::PolygonRenderer>())  GetComponent<ME::PolygonRenderer>().SetColour({ 255, 0, 0, 255 });
		if (HasComponent<ME::SpriteRenderer>())  GetComponent<ME::SpriteRenderer>().SetColour({ 255, 0, 0, 255 });
		
	}
};

int main(int argc, char* args[])
{
	ME::Engine::Init("Sandbox", 1920, 1080);

	ME::Engine::GetMainCamera().GetEntity().AddScript<CameraController>();
	ME::Engine::GetMainCamera().GetComponent<ME::Transform>().SetPosition({ 0, 0 });

	ME::SpriteRenderer renderer = ME::Engine::AddEntity().AddComponent<ME::SpriteRenderer>();
	renderer.SetColour({ 0, 120, 255, 255 });
	ME::RectangleCollider collider = renderer.AddComponent<ME::RectangleCollider>();
	collider.SetWidth(1400); collider.SetHeight(100);
	renderer.GetComponent<ME::Transform>().SetScale({ 1400, 100 });
	renderer.GetComponent<ME::Transform>().SetPosition({ 0, -450});
	renderer.GetComponent<ME::Transform>().SetRotation(0);
	renderer.AddComponent<ME::Rigidbody>().SetStatic(true);

	ME::SpriteRenderer renderer2 = ME::Engine::AddEntity().AddComponent<ME::SpriteRenderer>();
	ME::RectangleCollider collider2 = renderer2.AddComponent<ME::RectangleCollider>();
	collider2.SetWidth(100); collider2.SetHeight(100);
	renderer2.GetComponent<ME::Transform>().SetScale({ 100, 100 });
	renderer2.GetComponent<ME::Transform>().SetPosition({ -140, -30 });
	renderer2.GetComponent<ME::Transform>().SetRotation(30);
	renderer2.AddComponent<ME::Rigidbody>().SetGravityScale(30);

	ME::SpriteRenderer renderer3 = ME::Engine::AddEntity().AddComponent<ME::SpriteRenderer>();
	ME::RectangleCollider collider3 = renderer3.AddComponent<ME::RectangleCollider>();
	collider3.SetWidth(100); collider3.SetHeight(100);
	renderer3.GetComponent<ME::Transform>().SetScale({ 100, 100 });
	renderer3.GetComponent<ME::Transform>().SetPosition({ -300, -200 });
	renderer3.AddComponent<ME::Rigidbody>().SetGravityScale(30);
	
	ME::CircleRenderer circle = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circle.SetRadius(50);
	circle.AddComponent<ME::CircleCollider>().SetRadius(50);
	circle.AddComponent<ME::Rigidbody>().SetGravityScale(30);

	ME::CircleRenderer circle2 = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circle2.SetRadius(50);
	circle2.AddComponent<ME::CircleCollider>().SetRadius(50);
	circle2.AddComponent<ME::Rigidbody>().SetGravityScale(30);
	circle2.GetComponent<ME::Transform>().SetPosition({ 10, 300 });

	ME::CircleRenderer circle3 = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circle3.SetRadius(50);
	circle3.AddComponent<ME::CircleCollider>().SetRadius(50);
	circle3.AddComponent<ME::Rigidbody>().SetGravityScale(30);
	circle3.GetComponent<ME::Transform>().SetPosition({ -40, 450 });

	ME::CircleRenderer circle4 = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circle4.SetRadius(50);
	circle4.AddComponent<ME::CircleCollider>().SetRadius(50);
	circle4.AddComponent<ME::Rigidbody>().SetGravityScale(30);
	circle4.GetComponent<ME::Transform>().SetPosition({ -100, 180 });

	ME::CircleRenderer circle5 = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circle5.SetRadius(50);
	circle5.AddComponent<ME::CircleCollider>().SetRadius(50);
	circle5.AddComponent<ME::Rigidbody>().SetGravityScale(30);
	circle5.GetComponent<ME::Transform>().SetPosition({ 200, 100 });

	ME::CircleRenderer circle6 = ME::Engine::AddEntity().AddComponent<ME::CircleRenderer>();
	circle6.SetRadius(50);
	circle6.AddComponent<ME::CircleCollider>().SetRadius(50);
	circle6.AddComponent<ME::Rigidbody>().SetGravityScale(30);
	circle6.GetComponent<ME::Transform>().SetPosition({ -200, 400 });
	
	ME::Engine::Start();

	return 0;
}

