#include "Sprite.h"

namespace ME
{
	/* Default */
	Sprite::Sprite() :
		m_Texture(nullptr),
		colour(RGBA()),
		size(Vector2())
	{}

	/* Set Members */
	Sprite::Sprite(SDL_Texture* texture, const RGBA colour, const Vector2 size) :
		m_Texture(texture),
		colour(colour),
		size(size)
	{}

	/* Return SDL2 Texture */
	SDL_Texture* Sprite::GetTexture() const 
	{
		return m_Texture;
	}
}
