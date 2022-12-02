#include "Component.h"

namespace ME
{
	Component::Component() :
		p_Entity(nullptr)
	{}

	Component::Component(Entity* entity) :
		p_Entity(entity)
	{}

	unsigned int Component::GetEntityID() const
	{
		return p_Entity->GetID();
	}

	Entity Component::GetEntity() const
	{
		return *p_Entity;
	}
}
