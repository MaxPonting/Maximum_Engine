#pragma once

/* C++ */
#include <iostream>

/* ME */
#include "Window.h"
#include "Renderer.h"
#include "Arena.h"
#include "Entity.h"
#include "Component.h"
#include "Texture.h"
#include "Sprite.h"

namespace ME
{
	//
	// Owns window and render.
	// Starts the game loop when 'Run' is called.
	//
	// Template to change size of the contiguous memory allocation.
	//
	template <int MAX_ENTITIES, int MAX_EACH_COMPONENT, int MAX_TEXTURES>	
	class Engine
	{
	public:

		/* CONSTRUCTOR */
		/* Create Window and Renderer */
		Engine(const char* title, const int width, const int height) :
			m_Window(Window(title, width, height)),
			m_Renderer(Renderer(m_Window)),
			m_Event(SDL_Event()),
			m_Running(false)
		{}

		/* PUBLIC METHODS */
		/* Starts and holds game loop */
		void Run()
		{
			m_Running = true;

			while (m_Running)
			{
				UpdateEvents();
				UpdateScripts();
				UpdatePhysics();
				UpdateRenderer();
			}
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
		}

		/* Updates user-made Scripts */
		void UpdateScripts()
		{

		}

		/* Updates Rigidbodies and Colliders */
		void UpdatePhysics()
		{

		}

		/* Updates the renderer */
		void UpdateRenderer()
		{
			m_Renderer.Clear();

			m_Renderer.Present();
		}

		/* PRIVATE STACK ALLOCATED CONTAINERS */
		Arena<Entity, MAX_ENTITIES> m_EntityArena;
		Arena<Texture, MAX_TEXTURES> m_TextureArena;

		/* PRIVATE MEMBERS */
		Window m_Window;
		Renderer m_Renderer;
		SDL_Event m_Event;
		bool m_Running;

	};
}


