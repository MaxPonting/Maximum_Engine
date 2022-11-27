#pragma once

#include <string>

#include <SDL.h>

namespace ME
{
	class Window
	{
	public:

		/* CONSTRUCTOR */
		Window(const char* title, int width, int height);

		/* GETTERS */
		SDL_Window* GetWindow() const;
		
	private:

		/* PRIVATE MEMBERS */
		SDL_Window* m_Window;

	};
}


