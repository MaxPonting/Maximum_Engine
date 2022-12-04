#pragma once

#include "../ECS/TransformComponent.h"
#include "Sprite.h"

namespace ME
{
	class ObjectToRender
	{
	public:

		TransformComponent transform;
		Sprite sprite;
		unsigned int layer;

	};
}


