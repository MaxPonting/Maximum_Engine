#pragma once

#include "ComponentRef.h"
#include "../Helper/Vector2f.h"

namespace ME
{
	class Rigidbody : public ComponentRef
	{
	public:

		Rigidbody();
		Rigidbody(unsigned int id, ECS* ecs);

		void AddForce(const Vector2f force);
		void AddTorque(const float torque);
		void SetMass(const float mass);
		void SetGravityScale(const float scale);

		float GetMass();
		float GetGravityScale();
	};
}


