#include "Component.h"

namespace ME
{
	Component::Component() :
		m_EntityID(0),
		m_ComponentID(0)
	{}

	Component::Component(unsigned int entityID, unsigned int componentID) :
		m_EntityID(entityID),
		m_ComponentID(componentID)
	{}

	unsigned int Component::GetEntityID()
	{
		return m_EntityID;
	}

	unsigned int Component::GetComponentID()
	{
		return m_ComponentID;
	}
}
