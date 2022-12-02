#pragma once


#include "Renderer.h"
#include "Entity.h"

namespace ME
{
	class Component
	{
	public:

		/* CONSTRUCTORS */
		Component();
		Component(Entity* entity);

		/* PUBLIC METHODS */
		void virtual Update() {};
		void virtual Render(const Renderer& renderer) {};

		/* GETTERS */
		unsigned int GetEntityID() const;
		Entity GetEntity() const;

	private:

		/* PRIVATE MEMBERS */
		Entity* p_Entity;

	};
}


