#include "SpriteRenderer.h"

namespace ME
{

	SpriteRenderer::SpriteRenderer() : 
		Component(),
		m_Texture(nullptr),
		m_DefaultTexture(nullptr)
	{}

	SpriteRenderer::SpriteRenderer(Entity* entity, Texture* defaultTexture) : 
		Component(entity),
		m_DefaultTexture(defaultTexture),
		m_Texture(m_DefaultTexture)
	{}

	void SpriteRenderer::Render(const Renderer& renderer)
	{

	}

	void SpriteRenderer::SetTexture(Texture* texture)
	{
		m_Texture = texture;
	}

	void SpriteRenderer::SetSize(Vector2 size)
	{

	}

}
