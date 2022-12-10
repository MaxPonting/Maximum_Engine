#include "SpriteRendererComponent.h"

namespace ME
{
	SpriteRendererComponent::SpriteRendererComponent() : 
		Component(), 
		layer(0)
	{}

	SpriteRendererComponent::SpriteRendererComponent(const unsigned int entityID, const unsigned int componentID) : 
		Component(entityID, componentID),
		layer(0)
	{}
}
