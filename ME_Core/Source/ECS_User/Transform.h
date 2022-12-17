#pragma once

#include "ComponentRef.h"
#include "../Engine/Angle.h"
#include "../Engine/Vector2f.h"

namespace ME
{
	class Transform final : public ComponentRef
	{
	public:

		Transform();
		Transform(unsigned int entityID, ECS* ecs);

		void SetPosition(Vector2f position);
		void SetRotation(float rotation);
		void SetScale(Vector2f scale);

		Vector2f GetPosition();
		float GetRotation();
		Vector2f GetScale();
	};
}


