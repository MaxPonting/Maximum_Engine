/* C++ */
#include <algorithm>

/* ME */
#include "Renderer.h"
#include "Manager.h"

namespace ME
{
	Renderer::Renderer() :
		p_Renderer(nullptr),
		m_Info(SDL_RendererInfo())
	{}

	/* Creates SDL2 Renderer */
	Renderer::Renderer(const Window window)
	{		
		//SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
		SDLCall(SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1"));
		SDLCall(p_Renderer = SDL_CreateRenderer(window.GetWindow(), -1, SDL_RENDERER_ACCELERATED));
		SDLCall(SDL_RenderSetLogicalSize(p_Renderer, 1920, 1080));
		SDLCall(SDL_GetRendererInfo(p_Renderer, &m_Info));
	}

	/* Clears SDL2 renderer */
	void Renderer::Clear()
	{
		SDLCall(SDL_RenderClear(p_Renderer));
	}

	void Renderer::Enqueue(ObjectToRender object)
	{
		m_ObjectsToRender.emplace_back(object);
	}

	void Renderer::RenderQueue()
	{
		std::sort(m_ObjectsToRender.begin(), m_ObjectsToRender.end(),
			[](const ObjectToRender& o1, const ObjectToRender& o2) { return o1.layer < o2.layer; });

		for (int i = 0; i < m_ObjectsToRender.size(); i++)
		{
			RenderObject(m_ObjectsToRender[i]);
		}

		m_ObjectsToRender.clear();
	}

	/* Renders a sprite to the SDL2 window using a position */
	void Renderer::RenderSprite(const Sprite sprite, const Vector2f position) const
	{
		if (sprite.GetTexture() == nullptr) return;

		SDLCall(SDL_SetTextureColorMod
		(
			sprite.GetTexture(),
			sprite.colour.GetR(),
			sprite.colour.GetG(),
			sprite.colour.GetB()
		));

		SDLCall(SDL_SetTextureAlphaMod
		(
			sprite.GetTexture(),
			sprite.colour.GetA()
		));

		SDL_FRect rect;
		rect.x = position.X;
		rect.y = position.Y;
		rect.w = sprite.size.X;
		rect.h = sprite.size.Y;
		SDLCall(SDL_RenderCopyF
		(
			p_Renderer,
			sprite.GetTexture(),
			NULL,
			&rect
		));
	}

	/*Renders a sprite to the SDL2 window using a transform */
	void Renderer::RenderObject(const ObjectToRender object)
	{
		if (object.sprite.GetTexture() == nullptr) return;

		SDLCall(SDL_SetTextureColorMod
		(
			object.sprite.GetTexture(),
			object.sprite.colour.GetR(),
			object.sprite.colour.GetG(),
			object.sprite.colour.GetB()
		));

		SDLCall(SDL_SetTextureAlphaMod
		(
			object.sprite.GetTexture(),
			object.sprite.colour.GetA()
		));

		SDL_FRect rect;
		rect.x = object.transform.position.X;
		rect.y = object.transform.position.Y;
		rect.w = object.sprite.size.X * object.transform.scale.X;
		rect.h = object.sprite.size.Y * object.transform.scale.Y;

		SDLCall(SDL_RenderCopyExF
		(
			p_Renderer,
			object.sprite.GetTexture(),
			NULL,
			&rect,
			object.transform.rotation.getDeg(),
			NULL,
			SDL_FLIP_NONE
		));
	}

	/* Presents renderer sprites to the SDL2 window */
	void Renderer::Present(const Window window)
	{
		SDLCall(SDL_SetRenderDrawColor(
			p_Renderer,
			window.m_Colour.GetR(),
			window.m_Colour.GetG(),
			window.m_Colour.GetB(),
			window.m_Colour.GetA()
		));
		SDLCall(SDL_RenderPresent(p_Renderer));
	}
	
	void Renderer::SDLCleanUp()
	{
		SDLCall(SDL_DestroyRenderer(p_Renderer));
	}

	void Renderer::SetRenderTargetToTexture(SDL_Texture* texture) const
	{
		SDL_SetRenderTarget(p_Renderer, texture);
	}

	void Renderer::ResetRenderTarget() const
	{
		SDL_SetRenderTarget(p_Renderer, 0);
	}

	void Renderer::SetRenderDrawColor(RGBA color) const
	{
		SDL_SetRenderDrawColor(p_Renderer, color.GetR(), color.GetG(), color.GetB(), color.GetA());
	}

	void Renderer::RenderDrawPoint(int x, int y) const
	{
		SDL_RenderDrawPoint(p_Renderer, x, y);
	}

	SDL_Texture* Renderer::CreateTexture(SDL_TextureAccess access, int w, int h) const
	{
		SDLCall(SDL_Texture * texture = SDL_CreateTexture(p_Renderer, SDL_PIXELFORMAT_RGBA32, access, w, h));
		return texture;
	}

	/* Creates a SDL_Texture from a SDL_Surface */
	SDL_Texture* Renderer::CreateTextureFromSurface(SDL_Surface* surface) const
	{
		SDLCall(SDL_Texture* texture = SDL_CreateTextureFromSurface(p_Renderer, surface));
		return texture;
	}

	SDL_Texture* Renderer::CreateTextureFromFilePath(const char* filePath) const
	{
		return SDLCall(IMG_LoadTexture(p_Renderer, filePath));
	}

	SDL_RendererInfo Renderer::GetInfo()
	{
		return m_Info;
	}

	
}
