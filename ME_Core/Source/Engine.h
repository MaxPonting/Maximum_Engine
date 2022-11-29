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
#include "Debug.h"
#include "SDLWrapper.h"


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
			m_Debug(Debug(m_Renderer)),
			m_Time(EngineTime()),
			m_Running(false)
		{}

		/* PUBLIC METHODS */
		/* Starts and holds game loop */
		void Run()
		{
			m_Running = true;

			while (m_Running)
			{
				m_Time.Update();
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

			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Misc);
		}

		/* Updates user-made Scripts */
		void UpdateScripts()
		{
			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Script);
		}

		/* Updates Rigidbodies and Colliders */
		void UpdatePhysics()
		{
			m_Debug.Update(m_Time);

			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Physics);
		}

		/* Updates the renderer */
		void UpdateRenderer()
		{
			m_Renderer.Clear();


			m_Debug.Render();

			m_Renderer.Present();

			m_Time.UpdateSubFrame(EngineTime::SubFrameType::Renderer);
		}

		/* PRIVATE STACK ALLOCATED CONTAINERS */
		Arena<Entity, MAX_ENTITIES> m_EntityArena;
		Arena<Texture, MAX_TEXTURES> m_TextureArena;

		/* PRIVATE MEMBERS */
		Window m_Window;
		Renderer m_Renderer;
		SDL_Event m_Event;
		Debug m_Debug;
		EngineTime m_Time;
		bool m_Running;
	};
}


