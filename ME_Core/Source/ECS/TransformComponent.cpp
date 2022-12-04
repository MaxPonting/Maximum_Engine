#include "TransformComponent.h"

namespace ME
{
	TransformComponent::TransformComponent() : 
		Component(),
		position(Vector2()),
		rotation(0),
		scale(Vector2(1, 1))
	{}

	TransformComponent::TransformComponent(const unsigned int entityID, const unsigned int componentID) : 
		Component(entityID, componentID),
		position(Vector2()),
		rotation(0),
		scale(Vector2(1, 1))
	{}
}
