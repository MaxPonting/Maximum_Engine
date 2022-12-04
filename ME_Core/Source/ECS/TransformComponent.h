#pragma once

#include "Component.h"
#include "../Engine/Vector2.h"
#include "../Engine/Angle.h"

namespace ME
{
	class TransformComponent : public Component
	{
	public:

		TransformComponent();
		TransformComponent(const unsigned int entityID, const unsigned int componentID);

		Vector2 position;
		Angle rotation;
		Vector2 scale;

	};
}


