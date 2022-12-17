#pragma once

#include "SDL.h"

#include "SDLWrapper.h"

namespace ME
{
	class Texture
	{
	public:

		/* CONSTRUCTORS */
		Texture();
		Texture(unsigned int id);

		/* GETTERS */
		unsigned int GetTextureID() const;

	private:

		unsigned int m_TextureID;

	};
}


