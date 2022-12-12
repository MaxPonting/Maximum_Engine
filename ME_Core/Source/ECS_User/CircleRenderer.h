#pragma once

#include "ComponentRef.h"
#include "../Engine/Texture.h"
#include "../Engine/RGBA.h"

namespace ME
{
	class CircleRenderer final : public ComponentRef
	{
	public:

		CircleRenderer();
		CircleRenderer(unsigned int id, ECS* ecs);

		void SetRadius(unsigned int radius);
		void SetColour(RGBA colour);
		void SetLayer(int layer);

		unsigned int GetRadius();
		RGBA GetColour();
		int GetLayer();	
	};
}

