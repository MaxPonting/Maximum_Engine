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
		void RenderSprite(const Sprite sprite, const Vector2 position) const;
		void Present(const Window window);
		void SDLCleanUp();

		SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface) const;
		SDL_Texture* CreateTextureFromFilePath(const char* filePath) const;

	private:

		/* PRIVATE METHODS */
		void RenderObject(const ObjectToRender object);

		/* PRIVATE MEMBERS */
		SDL_Renderer* p_Renderer;
		std::vector<ObjectToRender> m_ObjectsToRender;

	};
}


