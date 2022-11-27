
/* ME */
#include "Renderer.h"
#include "Manager.h"

namespace ME
{
	/* Creates SDL2 Renderer */
	Renderer::Renderer(const Window& window) :
		c_Window(window)
	{
		SDLCall(m_Renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_ACCELERATED));
	}

	/* Clears SDL2 renderer */
	void Renderer::Clear()
	{
		SDLCall(SDL_RenderClear(m_Renderer));
	}

	/* Renders a sprite to the SDL2 window */
	void Renderer::RenderSprite(const Sprite sprite, const Transform transform)
	{
		
	}

	/* Presents renderer sprites to the SDL2 window */
	void Renderer::Present()
	{
		SDLCall(SDL_RenderPresent(m_Renderer));
	}
}
