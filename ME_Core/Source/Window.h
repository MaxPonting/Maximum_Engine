#pragma once

/* C++ */
#include <string>

/* SDL2 */
#include <SDL.h>

/* ME */
#include "Colour.h"

namespace ME
{
	/* 
	* Creates a SDL2 window.
	* Colour of window can be set.
	*/
	class Window
	{
	public:

		/* CONSTRUCTOR */
		Window(const char* title, int width, int height);

		/* GETTERS */
		SDL_Window* GetWindow() const;

		/* PUBLIC MEMBERS */
		Colour m_Colour;

	private:

		/* PRIVATE MEMBERS */
		SDL_Window* m_Window;
		
	};
}


