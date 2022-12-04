#include "SpriteRenderer.h"

namespace ME
{
	SpriteRenderer::SpriteRenderer() : ComponentRef() {}
	SpriteRenderer::SpriteRenderer(unsigned int id, ECS* ecs) : ComponentRef(id, ecs) {}

	void SpriteRenderer::SetTexture(Texture texture)
	{
		p_ECS->GetComponent<SpriteRendererComponent>(m_EntityID)->texture = texture;
	}

	void SpriteRenderer::SetColour(RGBA colour)
	{
		p_ECS->GetComponent<SpriteRendererComponent>(m_EntityID)->colour = colour;
	}

	void SpriteRenderer::SetLayer(unsigned int layer)
	{
		p_ECS->GetComponent<SpriteRendererComponent>(m_EntityID)->layer = layer;
	}

	Texture SpriteRenderer::GetTexture()
	{
		return p_ECS->GetComponent<SpriteRendererComponent>(m_EntityID)->texture;
	}

	RGBA SpriteRenderer::GetColour()
	{
		return p_ECS->GetComponent<SpriteRendererComponent>(m_EntityID)->colour;
	}

	unsigned int SpriteRenderer::GetLayer()
	{
		return p_ECS->GetComponent<SpriteRendererComponent>(m_EntityID)->layer;
	}
}
