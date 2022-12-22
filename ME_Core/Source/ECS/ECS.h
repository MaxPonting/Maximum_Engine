#pragma once

#include <type_traits>

#include "ComponentContainer.h"
#include "TransformComponent.h"
#include "SpriteRendererComponent.h"
#include "CircleRendererComponent.h"
#include "PolygonRendererComponent.h"
#include "TextRendererComponent.h"
#include "CameraComponent.h"
#include "ScriptComponent.h"

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
			m_Transforms(10000),
			m_SpriteRenderers(8000),
			m_CircleRenderers(100),
			m_PolygonRenderers(100),
			m_TextRenderers(1000)
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
			DestroyComponent<TransformComponent>(entityID);
			DestroyComponent<SpriteRendererComponent>(entityID);
			DestroyComponent<CircleRendererComponent>(entityID);
			DestroyComponent<PolygonRendererComponent>(entityID);
			DestroyComponent<TextRendererComponent>(entityID);
			DestroyComponent<CameraComponent>(entityID);
		}

		
		//
		// Returns a pointer to the vector of a given component.
		//
		template <class C>
		std::vector<C>* GetComponents()
		{
			if (std::is_same<TransformComponent, C>::value)
			return (std::vector<C>*)m_Transforms.GetAll();

			else if (std::is_same<SpriteRendererComponent, C>::value)
			return (std::vector<C>*)m_SpriteRenderers.GetAll();
			
			else if (std::is_same<CircleRendererComponent, C>::value)
			return (std::vector<C>*)m_CircleRenderers.GetAll();

			else if (std::is_same<PolygonRendererComponent, C>::value)
			return (std::vector<C>*)m_PolygonRenderers.GetAll();

			else if (std::is_same<TextRendererComponent, C>::value)
			return (std::vector<C>*)m_TextRenderers.GetAll();

			else if (std::is_same<CameraComponent, C>::value)
			return (std::vector<C>*)m_Cameras.GetAll();

			return nullptr;
		}


		//
		// Returns a pointer to a component given an entity ID and a component ID.
		//
		template <class C>
		C* GetComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			return (C*)m_Transforms.GetWithEntityID(entityID);
			
			else if (std::is_same<SpriteRendererComponent, C>::value)
			return (C*)m_SpriteRenderers.GetWithEntityID(entityID);
			
			else if (std::is_same<CircleRendererComponent, C>::value)
			return (C*)m_CircleRenderers.GetWithEntityID(entityID);
			
			else if (std::is_same<PolygonRendererComponent, C>::value)
			return (C*)m_PolygonRenderers.GetWithEntityID(entityID);

			else if (std::is_same<TextRendererComponent, C>::value)
			return (C*)m_TextRenderers.GetWithEntityID(entityID);

			else if (std::is_same<CameraComponent, C>::value)
			return (C*)m_Cameras.GetWithEntityID(entityID);

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
			return (C*)m_Transforms.Add(entityID);

			else if (std::is_same<SpriteRendererComponent, C>::value)
			{
				DestroyComponent<TextRendererComponent>(entityID);
				DestroyComponent<CircleRendererComponent>(entityID);
				DestroyComponent<PolygonRendererComponent>(entityID);
				return (C*)m_SpriteRenderers.Add(entityID);
			}
			
			else if (std::is_same<CircleRendererComponent, C>::value)
			{
				DestroyComponent<TextRendererComponent>(entityID);
				DestroyComponent<SpriteRendererComponent>(entityID);
				DestroyComponent<PolygonRendererComponent>(entityID);
				return (C*)m_CircleRenderers.Add(entityID);
			}
			
			else if (std::is_same<PolygonRendererComponent, C>::value)
			{
				DestroyComponent<TextRendererComponent>(entityID);
				DestroyComponent<CircleRendererComponent>(entityID);
				DestroyComponent<SpriteRendererComponent>(entityID);
				return (C*)m_PolygonRenderers.Add(entityID);
			}

			else if (std::is_same<TextRendererComponent, C>::value)
			{
				DestroyComponent<PolygonRendererComponent>(entityID);
				DestroyComponent<CircleRendererComponent>(entityID);
				DestroyComponent<SpriteRendererComponent>(entityID);
				return (C*)m_TextRenderers.Add(entityID);
			}

			if (std::is_same<CameraComponent, C>::value)
			return (C*)m_Cameras.Add(entityID);
			
			return nullptr;
		}


		//
		// Returns true if an entity has the given component.
		//
		template <class C>
		bool HasComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			return m_Transforms.GetWithEntityID(entityID) != nullptr;

			else if (std::is_same<SpriteRendererComponent, C>::value)
			return m_SpriteRenderers.GetWithEntityID(entityID) != nullptr;

			else if (std::is_same<CircleRendererComponent, C>::value)
			return m_CircleRenderers.GetWithEntityID(entityID) != nullptr;

			else if (std::is_same<PolygonRendererComponent, C>::value)
			return m_PolygonRenderers.GetWithEntityID(entityID) != nullptr;

			else if (std::is_same<TextRendererComponent, C>::value)
			return m_TextRenderers.GetWithEntityID(entityID) != nullptr;

			else if (std::is_same<CameraComponent, C>::value)
			return m_Cameras.GetWithEntityID(entityID) != nullptr;
		}


		//
		// Destroys a given component of an entity.
		//
		template <class C>
		void DestroyComponent(unsigned int entityID)
		{
			if (std::is_same<TransformComponent, C>::value)
			m_Transforms.DeleteWithEntityID(entityID);

			else if (std::is_same<SpriteRendererComponent, C>::value)
			m_SpriteRenderers.DeleteWithEntityID(entityID);
			
			else if (std::is_same<CircleRendererComponent, C>::value)
			m_CircleRenderers.DeleteWithEntityID(entityID);
			
			else if (std::is_same<PolygonRendererComponent, C>::value)
			m_PolygonRenderers.DeleteWithEntityID(entityID);

			else if (std::is_same<TextRendererComponent, C>::value)
			m_TextRenderers.DeleteWithEntityID(entityID);

			else if (std::is_same<CameraComponent, C>::value)
			m_Cameras.DeleteWithEntityID(entityID);
		}

		//
		// Returns a pointer to a vector of script pointers
		//
		std::vector<ScriptComponent*>* GetScripts()
		{
			return &m_Scripts;
		}
		
		//
	    // Returns a pointer to a ScriptComponent
		//
		template <class C>
		C* GetScript(unsigned int entityID)
		{
			static_assert(std::is_base_of<ScriptComponent, C>::value, "C must be a script!");

			for (int i = 0; i < m_Scripts.size(); i++)
			{
				if(m_Scripts[i]->GetEntityID() == entityID)
				{
					if (static_cast<C>(m_Scripts[i]))
					{
						return m_Scripts[i];
					}
				}
			}
		}

		//
		// Adds a given script to a entity using a unique ID
		//
		template <class C>
		C* AddScript(unsigned int entityID)
		{
			static_assert(std::is_base_of<ScriptComponent, C>::value, "C must be a script!");

			m_Scripts.emplace_back(new C(entityID, this));
			m_Scripts[m_Scripts.size() - 1]->Start();
			return (C*)m_Scripts[m_Scripts.size() - 1];
		}

		//
		// Returns true if a entity has a given script
		//
		template <class C>
		bool HasScript(unsigned int entityID)
		{
			static_assert(std::is_base_of<ScriptComponent, C>::value, "C must be a script!");

			for (int i = 0; i < m_Scripts.size(); i++)
			{
				if (m_Scripts[i]->GetEntityID() == entityID)
				{
					if (static_cast<C>(m_Scripts[i]))
					{
						return true;
					}
				}
			}

			return false;
		}

		//
		// Destroys a given script of a entity
		//
		template <class C>
		void DestroyScript(unsigned int entityID)
		{
			static_assert(std::is_base_of<ScriptComponent, C>::value, "C must be a script!");

			for (int i = 0; i < m_Scripts.size(); i++)
			{
				if (m_Scripts[i]->GetEntityID() == entityID)
				{
					if (static_cast<C>(m_Scripts[i]))
					{
						delete m_Scripts[i];
						m_Scripts.erase(m_Scripts.begin() + i);
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
		ComponentContainer<CircleRendererComponent> m_CircleRenderers;
		ComponentContainer<PolygonRendererComponent> m_PolygonRenderers;
		ComponentContainer<TextRendererComponent> m_TextRenderers;
		ComponentContainer<CameraComponent> m_Cameras;

		//
		// Vector of pointers to user defined scripts
		//
		std::vector<ScriptComponent*> m_Scripts;

	};
}


