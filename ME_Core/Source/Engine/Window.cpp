
/* ME */
#include "Window.h"
#include "Manager.h"

namespace ME
{
	Window::Window() :
		m_Window(nullptr),
		m_Colour(RGBA())
	{}

	/* 
	* Creates an SDL2 window.
	* Sets background colour to black.
	*/
	Window::Window(const char* title, int width, int height) :
		m_Colour(RGBA(0, 0, 0, 255))
	{
		SDLCall(m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN));
	}

	void Window::SDLCleanUp()
	{
		SDLCall(SDL_DestroyWindow(m_Window));
	}

	/* Returns SDL2 window */
	SDL_Window* Window::GetWindow() const
	{
		return m_Window;
	}

}
