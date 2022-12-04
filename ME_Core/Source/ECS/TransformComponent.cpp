#include "TransformComponent.h"

namespace ME
{
	TransformComponent::TransformComponent() : Component() {}
	TransformComponent::TransformComponent(const unsigned int entityID, const unsigned int componentID) : Component(entityID, componentID) {}
}
