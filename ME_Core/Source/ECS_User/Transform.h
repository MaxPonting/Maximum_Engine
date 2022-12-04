#pragma once

#include "ComponentRef.h"
#include "../Engine/Angle.h"
#include "../Engine/Vector2.h"

namespace ME
{
	class Transform final : public ComponentRef
	{
	public:

		Transform();
		Transform(unsigned int entityID, ECS* ecs);

		void SetPosition(Vector2 position);
		void SetRotation(float rotation);
		void SetScale(Vector2 scale);

		Vector2 GetPosition();
		float GetRotation();
		Vector2 GetScale();
	};
}


