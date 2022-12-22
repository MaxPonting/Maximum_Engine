#include "CameraComponent.h"

namespace ME
{
	CameraComponent::CameraComponent() :
		Component(),
		position(Vector2f()),
		scale(1)
	{}

	CameraComponent::CameraComponent(unsigned int entityID) :
		Component(entityID),
		position(Vector2f()),
		scale(1)
	{}
}
