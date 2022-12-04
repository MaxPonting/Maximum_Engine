#pragma once

#include <type_traits>

#include "ComponentContainer.h"
#include "SpriteRendererComponent.h"
#include "TransformComponent.h"

namespace ME
{
	//
	// Contains all components in unique containers.
	// Links all component objects to a unique entity IDs.
	// Stores all components in contiguous memory.
	//
	class ECS final
	{
	public:

		//
		// Allocate space to component containers.
		//
		ECS() :
			m_NextEntityID(0),
			m_Transforms(100),
			m_SpriteRenderers(100)
		{}


		//
		// Add a transform to this new entity.
		// Returns a unique ID for an entity.
		//
		unsigned int AddEntity()
		{
			AddComponent<TransformComponent>(++m_NextEntityID);
			return m_NextEntityID;
		}


		//
		// Destroys all components related to an entity.
		//
		void DestroyEntity(unsigned int entityID)
		{
			for (int i = 0; i < m_Transforms.GetCount(); i++)
			{
				if (m_Transforms[i]->GetEntityID() == entityID)
				{
					m_Transforms.Delete(i);
				}
			}

			for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
			{
				if (m_SpriteRenderers[i]->GetEntityID() == entityID)
				{
					m_SpriteRenderers.Delete(i);
				}
			}
		}

		
		// 
		// Returns the ID of a component's entity.
		//
		template <class C>
		unsigned int GetEntityOf(unsigned int componentID)
		{
			if (std::is_same<TransformComponent, C>::value)
			{				
				for (int i = 0; i < m_Transforms.GetCount(); i++)
				{
					if (m_Transforms[i]->GetComponentID() == componentID) return m_Transforms[i]->GetEntityID();
				}
			}
			else if (std::is_same<SpriteRendererComponent, C>::value)
			{				
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i]->GetComponentID() == componentID) return m_SpriteRenderers[i]->GetEntityID();
				}
			}
		}

		
		//
		// Returns a vector of pointers to all components.
		//
		template <class C>
		std::vector<C*> GetComponents()
		{
			std::vector<C*> components;

			if (std::is_same<TransformComponent, C>::value)
			{
				components.reserve(m_Transforms.GetCount());
				for (int i = 0; i < m_Transforms.GetCount(); i++)
				{
					components.push_back((C*)m_Transforms[i]);
				}
			}
			else if (std::is_same<SpriteRendererComponent, C>::value)
			{
				components.reserve(m_SpriteRenderers.GetCount());
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					components.push_back((C*)m_SpriteRenderers[i]);
				}
			}

			return components;
		}


		//
		// Returns a pointer to a component given an entity ID and a component ID.
		//
		template <class C>
		C* GetComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			{
				for (int i = 0; i < m_Transforms.GetCount(); i++)
				{
					if (m_Transforms[i]->GetEntityID() == entityID)
					{
						return (C*)m_Transforms[i];
					}
				}
				return nullptr;
			}
			else if (std::is_same<SpriteRendererComponent, C>::value)
			{
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i]->GetEntityID() == entityID)
					{
						return (C*)m_SpriteRenderers[i];
					}
				}
				return nullptr;
			}

			return nullptr;
		}


		//
		// Adds a given component to an entity using a unique ID.
		// Returns a pointer to this component.
		//
		template <class C>
		C* AddComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			{
				for (int i = 0; i < m_Transforms.GetCount(); i++)
				{
					if (m_Transforms[i]->GetEntityID() == entityID)
					{
						m_Transforms.Delete(i);
						break;
					}
				}

				return (C*)m_Transforms.Add(entityID);
			}
			else if (std::is_same<SpriteRendererComponent, C>::value)
			{
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i]->GetEntityID() == entityID) 
					{
						m_SpriteRenderers.Delete(i);
						break;
					}
				}

				return (C*)m_SpriteRenderers.Add(entityID);
			}

			return nullptr;
		}


		//
		// Returns true if an entity has the given component.
		//
		template <class C>
		bool HasComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			{
				for (int i = 0; i < m_Transforms.GetCount(); i++)
				{
					if (m_Transforms[i]->GetEntityID() == entityID)
					{
						return true;
					}
				}
			}
			else if (std::is_same<SpriteRendererComponent, C>::value)
			{
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i]->GetEntityID() == entityID)
					{
						return true;
					}
				}
			}
		}


		//
		// Destroys a given component of an entity.
		//
		template <class C>
		void DestroyComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			{
				for (int i = 0; i < m_Transforms.GetCount(); i++)
				{
					if (m_Transforms[i]->GetEntityID() == entityID)
					{
						m_Transforms.Delete(i);
						break;
					}
				}
			}
			else if (std::is_same<SpriteRendererComponent, C>::value)
			{
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i]->GetEntityID() == entityID) 
					{
						m_SpriteRenderers.Delete(i);
						break;
					}
				}				
			}
		}

	private:

		// Unique ID of next entity.
		unsigned int m_NextEntityID;

		//
		// Containers of components.
		// Each container allocates a unique ID for a new component.
		//
		ComponentContainer<TransformComponent> m_Transforms;
		ComponentContainer<SpriteRendererComponent> m_SpriteRenderers;

	};
}


