#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include "../Helper/Vector2f.h"

#define GRAVITY ME::Vector2f(0, -9.81)

namespace ME
{
	class RigidbodyComponent : public Component
	{
	public:

		RigidbodyComponent();
		RigidbodyComponent(unsigned int entityID);
		
		void Update(TransformComponent& transform, float deltaTime);
		void AddForce(Vector2f force);

		float Mass;
		float GravityScale;
		Vector2f Force;
		Vector2f Velocity;

	};
}