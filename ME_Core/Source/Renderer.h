#pragma once

/* SDL2 */
#include <SDL.h>

/* ME */
#include "Sprite.h"
#include "Transform.h"
#include "Window.h"
#include "SDLWrapper.h"

namespace ME
{
	/* 
	* Owns SDL2 renderer.
	* Renders sprites to the SDL2 Window at a given transform.
	*/
	class Renderer : public SDLWrapper
	{
	public:

		/* CONSTRUCTOR */
		Renderer();
		Renderer(const Window window);

		/* PUBLIC METHODS */
		void Clear();
		void RenderSprite(const Sprite sprite, const Transform transform) const;
		void Present(const Window window);
		void SDLCleanUp();
		SDL_Texture* CreateDefaultTexture() const;
		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface) const;

	private:

		/* PRIVATE MEMBERS */
		SDL_Renderer* m_Renderer;

	};
}


