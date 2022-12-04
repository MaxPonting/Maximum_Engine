#include "ComponentRef.h"

namespace ME
{
	ComponentRef::ComponentRef() :
		m_EntityID(0)
	{}

	ComponentRef::ComponentRef(unsigned int entityID) :
		m_EntityID(entityID)
	{}

	unsigned int ComponentRef::GetEntityID()
	{
		return m_EntityID;
	}
}
