#pragma once

#include <type_traits>

#include "../ECS//ECS.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace ME
{
	//
	// Related to a set of components.
	//
	class Entity
	{
	public:

		Entity() :
			p_ECS(nullptr),
			m_ID(0)
		{}

		Entity(ECS* ecs, unsigned int id) :
			p_ECS(ecs),
			m_ID(id)
		{}

		//
		// Adds a new component and relates it to this entity ID.
		//
		template <class C>
		C AddComponent()
		{
			static_assert(std::is_base_of<ComponentRef, C>::value, "C must inherit from ComponentRef!");

			if (std::is_same<Transform, C>::value)
			{
				p_ECS->AddComponent<TransformComponent>(m_ID);
			}
			else if (std::is_same<SpriteRenderer, C>::value)
			{
				p_ECS->AddComponent<SpriteRendererComponent>(m_ID);
			}
			
			return C(m_ID);
		}

		//
		// Returns a given component of the entity.
		//
		template <class C>
		C GetComponent()
		{
			static_assert(std::is_base_of<ComponentRef, C>::value, "C must be a component!");

			return C(m_ID);
		}

		//
		// Returns true if this entity has a given component.
		//
		template <class C>
		bool HasComponent()
		{
			static_assert(std::is_base_of<ComponentRef, C>::value, "C must be a component!");

			if (std::is_same<Transform, C>::value)
			{
				return p_ECS->HasComponent<TransformComponent>(m_ID);
			}
			else if (std::is_same<SpriteRenderer, C>::value)
			{
				return p_ECS->HasComponent<SpriteRendererComponent>(m_ID);
			}

			return false;
		}

		//
		// Destroys a given component of this entity.
		//
		template <class C>
		void DestroyComponent()
		{
			static_assert(std::is_base_of<ComponentRef, C>::value, "C must be a component!");

			if (std::is_same<Transform, C>::value)
			{
				p_ECS->DestroyComponent<TransformComponent>(m_ID);
			}
			else if (std::is_same<SpriteRenderer, C>::value)
			{
				p_ECS->DestroyComponent<SpriteRendererComponent>(m_ID);
			}
		}

		//
		// Return this entity's unique ID.
		//
		unsigned int GetID()
		{
			return m_ID;
		}


	private:

		ECS* p_ECS;
		unsigned int m_ID;

	};
}


