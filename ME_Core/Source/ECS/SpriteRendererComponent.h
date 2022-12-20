#pragma once

#include "Component.h"
#include "../Engine/Texture.h"
#include "../Engine/RGBA.h"

namespace ME
{
	class SpriteRendererComponent : public Component
	{
	public:

		SpriteRendererComponent();
		SpriteRendererComponent(const unsigned int entityID);

		Texture texture;
		RGBA colour;
		int layer;

	};
}


