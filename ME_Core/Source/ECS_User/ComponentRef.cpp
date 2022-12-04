#include "ComponentRef.h"

namespace ME
{
	ComponentRef::ComponentRef() :
		m_EntityID(0),
		p_ECS(nullptr)
	{}

	ComponentRef::ComponentRef(unsigned int entityID, ECS* ecs) :
		m_EntityID(entityID),
		p_ECS(ecs)
	{}

	unsigned int ComponentRef::GetEntityID()
	{
		return m_EntityID;
	}
}
