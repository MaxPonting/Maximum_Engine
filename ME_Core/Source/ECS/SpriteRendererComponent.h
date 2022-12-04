#pragma once

#include "Component.h"

namespace ME
{
	class SpriteRendererComponent : public Component
	{
	public:

		SpriteRendererComponent();
		SpriteRendererComponent(const unsigned int entityID, const unsigned int componentID);

	};
}


