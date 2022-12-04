
/* ME */
#include "Renderer.h"
#include "Manager.h"

namespace ME
{
	Renderer::Renderer() :
		m_Renderer(nullptr)
	{}

	/* Creates SDL2 Renderer */
	Renderer::Renderer(const Window window)
	{
		SDLCall(m_Renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_ACCELERATED));
	}

	/* Clears SDL2 renderer */
	void Renderer::Clear()
	{
		SDLCall(SDL_RenderClear(m_Renderer));
	}

	/* Renders a sprite to the SDL2 window using a transform */
	void Renderer::RenderSprite(const Sprite sprite, const TransformComponent transform) const
	{
		/*
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
		*/
	}

	/* Renders a sprite to the SDL2 window using a position */
	void Renderer::RenderSprite(const Sprite sprite, const Vector2 position) const
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
		rect.x = position.GetX();
		rect.y = position.GetY();
		rect.w = sprite.Size.GetX();
		rect.h = sprite.Size.GetY();
		SDLCall(SDL_RenderCopyF
		(
			m_Renderer,
			sprite.GetTexture(),
			NULL,
			&rect
		));
	}

	/* Presents renderer sprites to the SDL2 window */
	void Renderer::Present(const Window window)
	{
		SDLCall(SDL_SetRenderDrawColor(
			m_Renderer,
			window.m_Colour.GetR(),
			window.m_Colour.GetG(),
			window.m_Colour.GetB(),
			window.m_Colour.GetA()
		));
		SDLCall(SDL_RenderPresent(m_Renderer));
	}
	
	void Renderer::SDLCleanUp()
	{
		SDLCall(SDL_DestroyRenderer(m_Renderer));
	}

	/* Creates a 1x1 texture with colour white */
	SDL_Texture* Renderer::CreateDefaultTexture() const
	{
		SDLCall(SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, 80, 80, 32, SDL_PIXELFORMAT_RGBA32));
		Uint32* buffer = (Uint32*)surface->pixels;
	
		SDLCall(SDL_LockSurface(surface));

		Uint32 colour = SDL_MapRGBA(surface->format, 255, 255, 255, 255);
		buffer[0] = colour;

		SDLCall(SDL_UnlockSurface(surface));

		SDLCall(SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface));
		SDLCall(SDL_FreeSurface(surface));

		return texture;
	}

	/* Creates a SDL_Texture from a SDL_Surface */
	SDL_Texture* Renderer::CreateTextureFromSurface(SDL_Surface* surface) const
	{
		SDLCall(SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface));
		return texture;
	}
}
