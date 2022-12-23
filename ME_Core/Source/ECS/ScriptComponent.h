#pragma once

#include "Component.h"
#include "../ECS_User/Entity.h"
#include "../ECS/ECS.h"
#include "../Engine/EngineTime.h"

namespace ME
{
	
	class Entity;
	class ScriptComponent : public Component
	{
	public:

		ScriptComponent();
		ScriptComponent(unsigned int entityID, ECS* ecs);

		void virtual Start() {};
		void virtual Update() {};

		template<class C>
		C GetComponent()
		{
			return GetEntity().GetComponent<C>();
		}

		template<class C>
		C AddComponent()
		{
			return GetEntity().AddComponent<C>();
		}

		template<class C>
		bool AddComponent()
		{
			return GetEntity().HasComponent<C>();
		}

		template<class C>
		void DestroyComponent()
		{
			return GetEntity().DestroyComponent<C>();
		}

		Entity GetEntity();
				
	private:

		ECS* p_ECS;
		
	};
}


