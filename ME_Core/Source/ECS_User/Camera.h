#pragma once

#include "ComponentRef.h"

namespace ME
{
	class Camera final : public ComponentRef
	{
	public:

		Camera();
		Camera(unsigned int id, ECS* ecs);

		void SetPosition(Vector2f pos);
		void SetScale(float scale);

		Vector2f GetPosition();
		float GetScale();
	};
}


