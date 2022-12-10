#include "CircleRenderer.h"

namespace ME
{
	CircleRenderer::CircleRenderer() : ComponentRef() {}
	CircleRenderer::CircleRenderer(unsigned int id, ECS* ecs) : ComponentRef(id, ecs) {}

	void CircleRenderer::SetRadius(unsigned int radius)
	{
		p_ECS->GetComponent<CircleRendererComponent>(m_EntityID)->SetRadius(radius);
	}

	void CircleRenderer::SetColour(RGBA colour)
	{
		p_ECS->GetComponent<CircleRendererComponent>(m_EntityID)->colour = colour;
	}

	void CircleRenderer::SetLayer(unsigned int layer)
	{
		p_ECS->GetComponent<CircleRendererComponent>(m_EntityID)->layer = layer;
	}

	unsigned int CircleRenderer::GetRadius()
	{
		return p_ECS->GetComponent<CircleRendererComponent>(m_EntityID)->GetRadius();
	}

	RGBA CircleRenderer::GetColour()
	{
		return p_ECS->GetComponent<CircleRendererComponent>(m_EntityID)->colour;
	}

	unsigned int CircleRenderer::GetLayer()
	{
		return p_ECS->GetComponent<CircleRendererComponent>(m_EntityID)->layer;
	}
}




