#include <ME.h>

class Script : public ME::ScriptComponent
{
	using ScriptComponent::ScriptComponent;

	const int camera_move_speed = 500;
	const int camera_scale_speed = 10;

	ME::Transform transform;

	void Start()
	{
		transform = GetComponent<ME::Transform>();
	}

	void Update()
	{
		using namespace ME;

		transform.SetScale(
				transform.GetScale() + Vector2f{ camera_scale_speed * Engine::GetTime().DeltaTime * Engine::GetMouseWheel(),
				camera_scale_speed * Engine::GetTime().DeltaTime * Engine::GetMouseWheel()
		});

		if (Engine::GetKey(ME_KEYCODE_W))
			transform.SetPosition(transform.GetPosition() + Vector2f{ 0, camera_move_speed * Engine::GetTime().DeltaTime });
		if (Engine::GetKey(ME_KEYCODE_S))
			transform.SetPosition(transform.GetPosition() + Vector2f{ 0, -camera_move_speed * Engine::GetTime().DeltaTime });
		if (Engine::GetKey(ME_KEYCODE_A))
			transform.SetPosition(transform.GetPosition() + Vector2f{ -camera_move_speed * Engine::GetTime().DeltaTime, 0 });
		if (Engine::GetKey(ME_KEYCODE_D))
			transform.SetPosition(transform.GetPosition() + Vector2f{ camera_move_speed * Engine::GetTime().DeltaTime, 0 });
			
		if (!Engine::GetMouse(0)) return;

		ME::Vector2i pos = ME::Engine::GetWorldMousePosition();
		
		Transform entity = Engine::AddEntity().GetComponent<Transform>();
		entity.SetPosition(pos);
		
		CircleRenderer circle = entity.AddComponent<CircleRenderer>();
		circle.SetRadius(20);
		circle.AddComponent<Rigidbody>().SetGravityScale(2);
				
	}
};


int main(int argc, char* args[])
{
	using namespace ME;

	Engine::Init("Sandbox", 1920, 1080);

	Engine::GetMainCamera().AddScript<Script>();

	Engine::Start();

	return 0;
}

