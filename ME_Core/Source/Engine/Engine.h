#pragma once

/* C++ */
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

/* ME */
#include "Window.h"
#include "Debug.h"
#include "Input.h"
#include "../Rendering/Renderer.h"
#include "../Rendering/Sprite.h"
#include "../Rendering/TextureContainer.h"
#include "../Rendering/FontContainer.h"
#include "../ECS/ECS.h"
#include "../ECS/ScriptComponent.h"
#include "../ECS_User/Entity.h"
#include "../ECS_User/ComponentRef.h"
#include "../ECS_User/Camera.h"
#include "../User/Time.h"

namespace ME
{
	//
	// Owns window and render.
	// Starts the game loop when 'Start' is called.
	//	
	class Engine final
	{
	public:

		//
		// Initialization
		//
		static void Init(const char* title, const int width, const int height);

		//
		// Error Checking
		//
		static bool CheckSDLError();
		
		/* PUBLIC METHODS */
		static void Start();

		/* ECS API */
		static Entity AddEntity();
		static void DestroyEntity(Entity entity);
		
		/* TEXTURE API */
		static Texture AddTexture(const char* filePath);

		/* FONT API */
		static Font AddFont(const char* filePath);
		
		//
		// Getters
		//
		static Time GetTime();
		static Camera GetMainCamera();
		static bool GetKey(const unsigned char code);
		static bool GetKeyUp(const unsigned char code);
		static bool GetKeyDown(const unsigned char code);
				
	private:

		/* PRIVATE METHODS */
		static void Run();
		static void UpdateEvents();		
		static void UpdateComponents();					
		static void UpdatePhysics();		
		static void UpdateRenderer();
		
		/* PRIVATE MEMBERS */
		static Window m_Window;
		static Renderer m_Renderer;
		static ECS m_ECS;
		static Debug m_Debug;
		static EngineTime m_Time;
		static Input m_Input;
		static Camera m_MainCamera;
		static TextureContainer m_Textures;
		static FontContainer m_Fonts;
		static SDL_Event m_Event;
	
		
		enum class State { Null, Init, Running };
		static State m_State;
	};

}

/*
Wrapper for every SDL Call
//
	Prints a SDL error to the console
//
	Breaks if an error occurs
*/
#define SDLCall(x) x; if(ME::Engine::CheckSDLError()) __debugbreak();  

/*
	Wrapper for every TTF Call
//
	Prints a TTF error to the console
//
	Breaks if an error occurs
*/
#define TTFCall(x) x; if(ME::Engine::CheckSDLError()) __debugbreak();  

/* Defines prefix for a SDL Error */
#define SDL_Error "[SDL][Error][" + __LINE__ + "]"

/* Defines prefix for a ME Error */
#define ME_Error "[ME][Error][" + __LINE__ + "]"

/* Define prefix for ME Debug */
#define ME_Debug "[ME][Debug][" + __LINE__ + "]"


