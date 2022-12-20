#pragma once

#include "Component.h"
#include "../Engine/Vector2f.h"
#include "../Engine/Angle.h"

namespace ME
{
	class TransformComponent : public Component
	{
	public:

		TransformComponent();
		TransformComponent(const unsigned int entityID);

		Vector2f position;
		Angle rotation;
		Vector2f scale;

	};
}


