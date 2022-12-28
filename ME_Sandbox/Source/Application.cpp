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

		if (HasComponent<ME::PolygonRenderer>())  GetComponent<ME::PolygonRenderer>().SetColour({ 255, 255, 255, 255 });
	}	

	void OnCollision(ME::Collider collider)
	{
		//if (HasComponent<ME::PolygonRenderer>())  GetComponent<ME::PolygonRenderer>().SetColour({ 255, 0, 0, 255 });
		
	}
};


int main(int argc, char* args[])
{
	ME::Engine::Init("Sandbox", 1920, 1080);

	//ME::Engine::GetMainCamera().GetEntity().AddScript<CameraController>();

	

	ME::Engine::Start();

	return 0;
}
