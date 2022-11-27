#include "Texture.h"

namespace ME
{
	Texture::Texture(SDL_Texture* texture) :
		m_Texture(texture)
	{}

	SDL_Texture* Texture::GetTexture() const
	{
		return m_Texture;
	}
}
