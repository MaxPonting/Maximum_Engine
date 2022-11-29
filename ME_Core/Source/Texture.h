#pragma once

#include "SDL.h"

#include "SDLWrapper.h"

namespace ME
{
	class Texture : public SDLWrapper
	{
	public:

		/* CONSTRUCTORS */
		Texture();
		Texture(SDL_Texture* texture);

		/* METHODS */
		void SDLCleanUp();

		/* GETTERS */
		SDL_Texture* GetTexture() const;

	protected:

		/* PROTECTED MEMBERS */
		SDL_Texture* m_Texture;

	};
}


