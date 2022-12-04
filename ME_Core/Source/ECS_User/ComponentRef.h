#pragma once

#include "../ECS/ECS.h"

namespace ME
{
	class ComponentRef
	{
	public:

		ComponentRef();
		ComponentRef(unsigned int entityID, ECS* ecs);
		
		unsigned int GetEntityID();

	protected:

		unsigned int m_EntityID;
		ECS* p_ECS;
	
	};
}

