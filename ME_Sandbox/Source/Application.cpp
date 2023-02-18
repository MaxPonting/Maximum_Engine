#include <ME.h>

class Controller : public ME::ScriptComponent
{
	using ME::ScriptComponent::ScriptComponent;

	void Update()
	{
		using namespace ME;

		if (Engine::GetKeyDown(ME_KEYCODE_SPACE))
		{
			CreateCircleBody(GetRandomPosition(), 50, 3);
		}
	}

	void CreateCircleBody(const ME::Vector2f pos, const float radius, const float mass)
	{
		using namespace ME;

		Rigidbody body = Engine::AddEntity().AddComponent<Rigidbody>();
		body.GetComponent<Transform>().SetPosition(pos);
		body.AddComponent<CircleRenderer>().SetRadius(radius);
		body.AddComponent<CircleCollider>().SetRadius(radius);

		body.SetGravityScale(50);
		body.SetMass(mass);
		body.SetRestitution(0.5f);
	}

	ME::Vector2f GetRandomPosition()
	{
		float xPos = rand() % 2000;
		xPos -= 1000;

		float yPos = 500 + (rand() % 200);

		return { xPos, yPos };
	}
};

int main(int argc, char* args[])
{
	using namespace ME;

	Engine::Init("Sandbox", 1920, 1080);

	Engine::AddEntity().AddScript<Controller>();
	
	Engine::Start();

	return 0;
}

