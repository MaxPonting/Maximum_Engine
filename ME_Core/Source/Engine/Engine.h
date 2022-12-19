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
#include "FontContainer.h"
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
		void DestroyEntity(Entity entity);
		
		/* TEXTURE API */
		Texture AddTexture(const char* filePath);

		/* FONT API */
		Font AddFont(const char* filePath);
					
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
		FontContainer m_Fonts;
		SDL_Event m_Event;
		Debug m_Debug;
		EngineTime m_Time;
		bool m_Running;
	};
}


