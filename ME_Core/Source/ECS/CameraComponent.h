#pragma once

#include "Component.h"
#include "../Engine/Vector2f.h"

namespace ME
{
	class CameraComponent final : public Component
	{
	public:

		CameraComponent();
		CameraComponent(unsigned int entityID);

	};
}


