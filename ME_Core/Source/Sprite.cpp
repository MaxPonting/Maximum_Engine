#include "Sprite.h"

namespace ME
{
	/* Set Members */
	Sprite::Sprite(const Texture& texture, const Colour colour, const Vector2 size) :
		m_Texture(texture),
		m_Colour(colour),
		m_Size(size)
	{}

	/* Return SDL2 Texture */
	SDL_Texture* Sprite::GetTexture()
	{
		return m_Texture.GetTexture();
	}
}
