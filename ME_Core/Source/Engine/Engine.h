#pragma once

/* C++ */
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

/* ME */
#include "Window.h"
#include "Renderer.h"
#include "Arena.h"
#include "Texture.h"
#include "Sprite.h"
#include "Debug.h"
#include "Texture.h"
#include "TextureContainer.h"
#include "../ECS/ECS.h"
#include "../ECS_User/Entity.h"
#include "../ECS_User/ComponentRef.h"

namespace ME
{
	//
	// Owns window and render.
	// Starts the game loop when 'Run' is called.
	//	
	class Engine final
	{
	public:

		/* CONSTRUCTORS */
		Engine();				
		Engine(const char* title, const int width, const int height);
		
		/* PUBLIC METHODS */
		void Run();

		/* ECS API */
		Entity AddEntity();
		template <class C>
		Entity GetEntityOf(C component)
		{
			unsigned int id = *static_cast<ComponentRef>(&component).GetID();
			return Entity(&m_ECS, m_ECS.GetEntityOf<C>(id));
		}
		void DestroyEntity(Entity entity);
		
		/* TEXTURE API */
		Texture AddTextureWithFilePath(const char* filePath);
					
	private:

		/* PRIVATE METHODS */
		void UpdateEvents();		
		void UpdateComponents();					
		void UpdatePhysics();		
		void UpdateRenderer();
		
		/* PRIVATE MEMBERS */
		Window m_Window;
		Renderer m_Renderer;
		ECS m_ECS;
		TextureContainer m_Textures;
		SDL_Event m_Event;
		Debug m_Debug;
		EngineTime m_Time;
		bool m_Running;
	};
}


