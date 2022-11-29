#pragma once

#include "Entity.h"

namespace ME
{
	class Component
	{
	public:

		Component();
		Component(const Entity* entity);

	protected:

		Entity* c_Entity;
	};
}


