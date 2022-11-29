
/* ME */
#include "Renderer.h"
#include "Manager.h"

namespace ME
{
	/* Creates SDL2 Renderer */
	Renderer::Renderer(const Window& window) :
		c_Window(window)
	{
		SDLCall(m_Renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
	}

	/* Clears SDL2 renderer */
	void Renderer::Clear()
	{
		SDLCall(SDL_RenderClear(m_Renderer));
	}

	/* Renders a sprite to the SDL2 window */
	void Renderer::RenderSprite(const Sprite sprite, const Transform transform) const
	{
		if (sprite.GetTexture() == nullptr) return;

		SDLCall(SDL_SetTextureColorMod
		(
			sprite.GetTexture(), 
			sprite.Colour.GetR(), 
			sprite.Colour.GetG(), 
			sprite.Colour.GetB()
		));

		SDLCall(SDL_SetTextureAlphaMod
		(
			sprite.GetTexture(),
			sprite.Colour.GetA()
		));

		SDL_FRect rect;
		rect.x = transform.Position.GetX(); 
		rect.y = transform.Position.GetY();
		rect.w = sprite.Size.GetX() * transform.Scale.GetX();
		rect.h = sprite.Size.GetY() * transform.Scale.GetY();

		SDLCall(SDL_RenderCopyExF
		(
			m_Renderer, 
			sprite.GetTexture(), 
			NULL, 
			&rect, 
			transform.Rotation.getDeg(), 
			NULL, 
			SDL_FLIP_NONE
		));
	}

	/* Presents renderer sprites to the SDL2 window */
	void Renderer::Present()
	{
		SDLCall(SDL_SetRenderDrawColor(
			m_Renderer,
			c_Window.m_Colour.GetR(),
			c_Window.m_Colour.GetG(),
			c_Window.m_Colour.GetB(),
			c_Window.m_Colour.GetA()
		));
		SDLCall(SDL_RenderPresent(m_Renderer));
	}
	
	void Renderer::SDLCleanUp()
	{
		SDLCall(SDL_DestroyRenderer(m_Renderer));
	}

	/* Creats a SDL_Texture from a SDL_Surface */
	SDL_Texture* Renderer::CreateTextureFromSurface(SDL_Surface* surface) const
	{
		SDLCall(SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface));
		return texture;
	}
}
