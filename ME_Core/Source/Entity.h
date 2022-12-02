#pragma once

#include "Transform.h"
#include <string>

namespace ME
{
	class Entity
	{
	public:

		/* CONSTRUCTOR */
		Entity();
		Entity(unsigned int id);

		/* GETTER */
		unsigned int GetID() const;

		/* PUBLIC MEMBERS */
		Transform transform;
		std::string name;
		unsigned int layer;

	private:

		/* PRIVATE MEMBERS */
		unsigned int m_ID;
		
	};
}


