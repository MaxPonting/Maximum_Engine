#pragma once

/* C++ */
#include <string>

/* SDL2 */
#include <SDL.h>

/* ME */
#include "RGBA.h"
#include "SDLWrapper.h"
#include "Vector2i.h"

namespace ME
{
	/* 
	* Creates a SDL2 window.
	* Colour of window can be set.
	*/
	class Window final : public SDLWrapper
	{
	public:

		/* CONSTRUCTOR */
		Window();
		Window(const char* title, int width, int height);

		/* PUBLIC METHODS */
		void SDLCleanUp();

		/* GETTERS */
		SDL_Window* GetWindow() const;
		Vector2i GetSize() const;

		/* PUBLIC MEMBERS */
		RGBA m_Colour;

	private:

		/* PRIVATE MEMBERS */
		SDL_Window* p_Window;
		
	};
}


