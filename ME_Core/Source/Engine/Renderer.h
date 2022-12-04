#pragma once

/* SDL2 */
#include <SDL.h>

/* ME */
#include "Sprite.h"
#include "../ECS/TransformComponent.h"
#include "Window.h"
#include "SDLWrapper.h"

namespace ME
{
	/* 
	* Owns SDL2 renderer.
	* Renders sprites to the SDL2 Window at a given transform.
	*/
	class Renderer final : public SDLWrapper 
	{
	public:

		/* CONSTRUCTOR */
		Renderer();
		Renderer(const Window window);

		/* PUBLIC METHODS */
		void Clear();
		void virtual RenderSprite(const Sprite sprite, const TransformComponent transform) const;
		void virtual RenderSprite(const Sprite sprite, const Vector2 position) const;
		void Present(const Window window);
		void SDLCleanUp();
		SDL_Texture* CreateDefaultTexture() const;
		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface) const;

	private:

		/* PRIVATE MEMBERS */
		SDL_Renderer* m_Renderer;

	};
}


