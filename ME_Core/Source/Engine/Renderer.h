#pragma once

/* C++ */
#include <vector>

/* SDL2 */
#include <SDL.h>
#include <SDL_image.h>

/* ME */
#include "Sprite.h"
#include "../ECS/TransformComponent.h"
#include "ObjectToRender.h"
#include "Window.h"
#include "SDLWrapper.h"

namespace ME
{
	//
	// Owns SDL2 renderer.
	// Renders sprites to the SDL2 Window at a given transform.
	//
	class Renderer final : public SDLWrapper 
	{
	public:

		/* CONSTRUCTOR */
		Renderer();
		Renderer(const Window window);

		/* PUBLIC METHODS */
		void Clear();
		void Enqueue(ObjectToRender object);
		void RenderQueue();
		void RenderSprite(const Sprite sprite, const Vector2f position) const;
		void Present(const Window window);
		void SDLCleanUp();

		void SetRenderTargetToTexture(SDL_Texture* texture) const;
		void ResetRenderTarget() const;
		void SetRenderDrawColor(RGBA color) const;
		void RenderDrawPoint(int x, int y) const;

		SDL_Texture* CreateTexture(SDL_TextureAccess access, int w, int h) const;
		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface) const;
		SDL_Texture* CreateTextureFromFilePath(const char* filePath) const;

		SDL_RendererInfo GetInfo();

	private:

		/* PRIVATE METHODS */
		void RenderObject(const ObjectToRender object);

		/* PRIVATE MEMBERS */
		SDL_Renderer* p_Renderer;
		SDL_RendererInfo m_Info;
		std::vector<ObjectToRender> m_ObjectsToRender;

	};
}


