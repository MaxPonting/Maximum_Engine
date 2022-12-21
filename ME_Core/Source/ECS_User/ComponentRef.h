#pragma once

#include "../ECS/ECS.h"


namespace ME
{
	class Entity;
	class ComponentRef
	{
	public:

		ComponentRef();
		ComponentRef(unsigned int entityID, ECS* ecs);
		
		Entity GetEntity();
		unsigned int GetEntityID();

	protected:

		unsigned int m_EntityID;
		ECS* p_ECS;
	
	};
}

