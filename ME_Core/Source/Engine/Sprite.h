#pragma once

/* SDL2 */
#include "SDL.h"

/* ME */
#include "RGBA.h"
#include "Texture.h"
#include "Vector2.h"

namespace ME
{
	//
	// Own an texture, colour and size.
	// Used to render a texture to a window.
	//
	class Sprite
	{
	public:

		/* CONSTRUCTORS */
		Sprite();
		Sprite(SDL_Texture* texture, const RGBA colour, const Vector2 size);

		/* GETTERS */
		SDL_Texture* GetTexture() const ;
		
		/* PUBLIC MEMBERS */
		RGBA colour;
		Vector2 size;

	private:

		/* PRIVATE MEMBERS */
		SDL_Texture* m_Texture;
		
	};
}


