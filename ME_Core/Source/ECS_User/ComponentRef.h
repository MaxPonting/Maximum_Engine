#pragma once

#include "../ECS/ECS.h"
#include "../ECS_User/Entity.h"

namespace ME
{
	class ComponentRef
	{
	public:

		ComponentRef();
		ComponentRef(unsigned int entityID, ECS* ecs);
		
		Entity GetEntity();
		unsigned int GetEntityID();

		template <class C>
		C AddComponent()
		{
			return Entity(p_ECS, m_EntityID).AddComponent<C>();
		}

		template <class C>
		C GetComponent()
		{
			return Entity(p_ECS, m_EntityID).GetComponent<C>();
		}

		template <class C>
		bool HasComponent()
		{
			return Entity(p_ECS, m_EntityID).HasComponent<C>();
		}

		template <class C>
		void DestroyComponent()
		{
			Entity(p_ECS, m_EntityID).DestroyComponent<C>();
		}

	protected:

		unsigned int m_EntityID;
		ECS* p_ECS;
	
	};
}

