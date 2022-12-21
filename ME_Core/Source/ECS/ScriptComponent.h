#pragma once

#include "Component.h"
#include "../Engine/EngineTime.h"

namespace ME
{
	class ECS;
	class Entity;
	class ScriptComponent : public Component
	{
	public:

		ScriptComponent();
		ScriptComponent(unsigned int entityID, ECS* ecs);

		void virtual Update() {};

		Entity GetEntity();
				
	private:

		ECS* p_ECS;
		
	};
}


