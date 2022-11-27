
/* ME */
#include "Window.h"
#include "Manager.h"

namespace ME
{
	/* Creates an SDL2 window */
	Window::Window(const char* title, int width, int height)
	{
		SDLCall(m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));
	}

	/* Returns SDL2 window */
	SDL_Window* Window::GetWindow() const
	{
		return m_Window;
	}

}
