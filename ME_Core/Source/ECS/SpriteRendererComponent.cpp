#include "SpriteRendererComponent.h"

namespace ME
{
	SpriteRendererComponent::SpriteRendererComponent() : 
		Component(), 
		layer(0)
	{}

	SpriteRendererComponent::SpriteRendererComponent(const unsigned int entityID) : 
		Component(entityID),
		layer(0)
	{}
}
