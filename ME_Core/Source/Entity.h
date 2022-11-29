#pragma once

#include <vector>

#include "Transform.h"
#include "Component.h"


namespace ME
{
	class Entity
	{
	public:

		/* CONSTRUCTOR */
		Entity();

		/* PUBLIC METHODS */
		void Update();
		void Render();

		/* PUBLIC MEMBERS */
		Transform Transform;
		
	private:

		/* PRIVATE MEMBERS */
		std::vector<Component*> p_Components;

	};
}


