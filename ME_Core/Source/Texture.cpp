#include "Texture.h"
#include "Manager.h"

namespace ME
{
	Texture::Texture() :
		m_Texture(nullptr)
	{}


	Texture::Texture(SDL_Texture* texture) :
		m_Texture(texture)
	{}

	void Texture::SDLCleanUp()
	{
		SDLCall(SDL_DestroyTexture(m_Texture));
	}

	SDL_Texture* Texture::GetTexture() const
	{
		return m_Texture;
	}
}
