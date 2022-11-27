#pragma once

/* SDL2 */
#include "SDL.h"

/* ME */
#include "Colour.h"
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
		Sprite(const Texture& texture, const Colour colour, const Vector2 size);

		/* GETTERS */
		SDL_Texture* GetTexture();

	private:

		/* PRIVATE MEMBERS */
		const Texture& m_Texture;
		const Colour m_Colour;
		const Vector2 m_Size;

	};
}


