#pragma once

#include "SDL.h"

namespace ME
{
	class Texture
	{
	public:

		/* CONSTRUCTORS */
		Texture(SDL_Texture* texture);

		/* GETTERS */
		SDL_Texture* GetTexture() const;

	private:

		/* PRIVATE MEMBERS */
		SDL_Texture* m_Texture;

	};
}


