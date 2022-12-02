#include "Entity.h"

namespace ME
{
	Entity::Entity() :
		m_ID(0),
		transform(Transform())
	{}

	Entity::Entity(unsigned int id) :
		m_ID(id),
		transform(Transform())
	{}

	unsigned int Entity::GetID() const
	{
		return m_ID;
	}
}
