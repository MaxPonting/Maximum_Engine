#pragma once

/* C++ */
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

/* ME */
#include "Vector2.h"
#include "Window.h"
#include "Renderer.h"
#include "Arena.h"
#include "Entity.h"
#include "Texture.h"
#include "Sprite.h"
#include "Debug.h"
#include "SpriteRenderer.h"
#include "TextRenderer.h"

namespace ME
{
	//
	// Owns window and render.
	// Starts the game loop when 'Run' is called.
	//
	// Template to change size of the contiguous memory allocation.
	//
	template <int ESTIMATED_ENTITIES, int ESTIMATED_COMPONENTS>	
	class Engine final
	{
	public:

		/* CONSTRUCTORS */
		Engine() :
			m_Window(Window()),
			m_Renderer(Renderer()),
			m_Event(SDL_Event()),
			m_Debug(Debug()),
			m_Time(EngineTime()),
			m_Running(false),
			m_EntityID(0),
			m_DefaultTexture(Texture())
		{}

		/* Create Window and Renderer */
		Engine(const char* title, const int width, const int height) :
			m_Window(Window(title, width, height)),
			m_Renderer(Renderer(m_Window)),
			m_Event(SDL_Event()),
			m_Debug(Debug(&m_Renderer)),
			m_Time(EngineTime()),
			m_Running(false),
			m_EntityID(0)
		{
			m_DefaultTexture = m_Renderer.CreateDefaultTexture();
		}

		/* PUBLIC METHODS */
		/* Starts and holds game loop */
		void Run()
		{
			m_Running = true;

			while (m_Running)
			{
				m_Time.Update();
				UpdateEvents();
				UpdateComponents();
				UpdatePhysics();
				UpdateRenderer();
			}

			m_DefaultTexture.SDLCleanUp();
			m_Renderer.SDLCleanUp();
			m_Window.SDLCleanUp();
		}

		/* Add Entity */
		const Entity* AddEntity()
		{
			m_EntityID++;
			return &m_Entities.Add(Entity(m_EntityID));
		}

		/* Get Entity with id */
		const Entity* GetEntity(unsigned int id)
		{
			for (int i = 0; i < m_Entities.GetCount(); i++)
			{
				if (m_Entities[i].GetID() == id)
				{
					return &m_Entities[i];
				}
			}
			return nullptr;
		}

		/* Get Entity with name */
		const Entity* GetEntityWithName(std::string name)
		{
			for (int i = 0; i < m_Entities.GetCount(); i++)
			{
				if (m_Entities[i].name == name)
				{
					return &m_Entities[i];
				}
			}
			return nullptr;
		}

		/* Destroy Entity */
		void DestroyEntity(const Entity entity)
		{
			if (!(HasEntity(entity.GetID()))) return;

			for (int i = 0; i < m_Entities.GetCount(); i++)
			{
				if (entity.GetID() == m_Entities[i].GetID())
				{
					m_Entities.Delete(i);
					break;
				}
			}

			for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
			{
				if (m_SpriteRenderers[i].GetEntityID() == entity.GetID())
				{
					m_SpriteRenderers.Delete(i);
				}
			}

			for (int i = 0; i < m_TextRenderers.GetCount(); i++)
			{
				if (m_TextRenderers[i].GetEntityID() == entity.GetID())
				{
					m_TextRenderers.Delete(i);
				}
			}
		}

		/* Check Entity is valid */
		bool HasEntity(const unsigned int id)
		{
			for (int i = 0; i < m_Entities.GetCount(); i++)
			{
				if (m_Entities[i].GetID() == id)
				{
					return true;
				}
			}

			return false;
		}

		/* Add Component */
		template <class C>
		const C* AddComponent(const Entity entity)
		{
			static_assert(std::is_base_of<Component, C>::value, "C must inherit from Component!");
			
			if (!(HasEntity(entity.GetID()))) return nullptr;

			if (std::is_same<SpriteRenderer, C>::value)
			{
				return &m_SpriteRenderers.Add(SpriteRenderer(GetEntityPointer(entity.GetID()), &m_DefaultTexture));
			
			}
			else if (std::is_same<TextRenderer, C>::value)
			{
				//return &m_TextRenderers.Add(TextRenderer(GetEntityPointer(entity.GetID())));			
			}
			else
			{
				return nullptr;
			}
		}

		/* Has Component */
		template <class C>
		bool HasComponent(const Entity entity)
		{
			static_assert(std::is_base_of<Component, C>, "C must inherit from Component!");

			if (!(HasEntity(entity.GetID()))) return false;

			if (std::is_same<SpriteRenderer, C>)
			{
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i].GetEntityID() == entity.GetID())
					{
						return true;
					}
				}
			}
			else if (std::is_same<TextRenderer, C>)
			{
				for (int i = 0; i < m_TextRenderers.GetCount(); i++)
				{
					if (m_TextRenderers[i].GetEntityID() == entity.GetID())
					{
						return true;
					}
				}
			}
			else
			{
				return false;
			}
		}

		/* Get Component */
		template <class C>
		const C* GetComponent(const Entity entity)
		{
			static_assert(std::is_base_of<Component, C>::value, "C must inherit from Component!");

			if (!(HasEntity(entity.GetID()))) return nullptr;

			if (std::is_same<SpriteRenderer, C>::value)
			{
				for (int i = 0; i < m_SpriteRenderers.GetCount(); i++)
				{
					if (m_SpriteRenderers[i].GetEntityID() == entity.GetID())
					{
						return &m_SpriteRenderers[i];
					}
				}
				return nullptr;
			}
			else if (std::is_same<TextRenderer, C>::value)
			{
				for (int i = 0; i < m_TextRenderers.GetCount(); i++)
				{
					if (m_TextRenderers[i].GetEntityID() == entity.GetID())
					{
						//return &m_TextRenderers[i];
					}
				}
				return nullptr;
			}
			
			return nullptr;
		}

		
	private:

		/* PRIVATE METHODS */
		/* Polls SDL2 events */
		void UpdateEvents()
		{
			while(SDL_PollEvent(&m_Event))
			{
				if (m_Event.type == SDL_QUIT)
				{
					m_Running = false;
				}
			}

			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Misc);
		}

		/* Updates user-made Scripts and non-physics components */
		void UpdateComponents()
		{
			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Script);
		}

		/* Updates Rigidbodies and Colliders */
		void UpdatePhysics()
		{
			m_Debug.Update(m_Time);

			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Physics);
		}

		//
		// Updates the renderer.
		// Call render components starting at lowest layer.
		// Renders debug overlay.
		//
		void UpdateRenderer()
		{
			m_Renderer.Clear();

			std::vector<Component*> renderComponents;
			renderComponents.reserve(
				m_SpriteRenderers.GetCount() +
				m_TextRenderers.GetCount()
			);

			for (int i = 0; i < m_SpriteRenderers.GetCount(); i++) 
			{ 
				renderComponents.push_back(&m_SpriteRenderers[i]); 
			}
			for (int i = 0; i < m_TextRenderers.GetCount(); i++)
			{
				renderComponents.push_back(&m_TextRenderers[i]);
			}
			
			std::sort(renderComponents.begin(), renderComponents.end(),
				[](const Component* p1, const Component* p2) { return p1->GetEntity().layer < p2->GetEntity().layer; });

			for (int i = 0; i < renderComponents.size(); i++)
			{
				renderComponents[i]->Render(m_Renderer);
			}

			m_Debug.Render();

			m_Renderer.Present(m_Window);

			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Renderer);
		}

		Entity* GetEntityPointer(unsigned int id)
		{
			for (int i = 0; i < m_Entities.GetCount(); i++)
			{
				if (m_Entities[i].GetID() == id)
				{
					return &m_Entities[i];
				}
			}
		}
		

		/* PRIVATE STACK ALLOCATED CONTAINERS OF COMPONENTS */
		Arena<Entity, ESTIMATED_ENTITIES> m_Entities;
		Arena<SpriteRenderer, ESTIMATED_COMPONENTS> m_SpriteRenderers;
		Arena<TextRenderer, ESTIMATED_COMPONENTS> m_TextRenderers;

		/* PRIVATE STACK ALLOCATED CONTAINERS OF TEXTURES */
		Arena<Texture, 100> m_Textures;

		/* DEFAULT TEXTURE FOR SPRITE-RENDERERS */
		Texture m_DefaultTexture;

		/* PRIVATE MEMBERS */
		Window m_Window;
		Renderer m_Renderer;
		SDL_Event m_Event;
		Debug m_Debug;
		EngineTime m_Time;
		bool m_Running;
		unsigned int m_EntityID;
	
	};
}


