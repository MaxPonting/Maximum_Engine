#pragma once

#include "Component.h"

namespace ME
{
	class TransformComponent : public Component
	{
	public:

		TransformComponent();
		TransformComponent(const unsigned int entityID, const unsigned int componentID);

	};
}


