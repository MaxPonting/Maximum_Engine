#pragma once

/* SDL2 */
#include <SDL.h>

/* ME */
#include "Sprite.h"
#include "Transform.h"
#include "Window.h"

namespace ME
{
	class Renderer
	{
	public:

		/* CONSTRUCTOR */
		Renderer(const Window& window);

		/* PUBLIC METHODS */
		void Clear();
		void RenderSprite(const Sprite sprite, const Transform transform);
		void Present();

	private:

		/* PRIVATE MEMBERS */
		SDL_Renderer* m_Renderer;

		/* CONST PRIVATE MEMBERS */
		const Window& c_Window;
	};
}


