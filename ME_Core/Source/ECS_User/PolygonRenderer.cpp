#include "PolygonRenderer.h"

namespace ME
{
	PolygonRenderer::PolygonRenderer() : ComponentRef() {}
	PolygonRenderer::PolygonRenderer(unsigned int id, ECS* ecs) : ComponentRef(id, ecs) {}

	void PolygonRenderer::SetPolygon(Polygon polygon)
	{
		p_ECS->GetComponent<PolygonRendererComponent>(m_EntityID)->SetPolygon(polygon);
	}

	void PolygonRenderer::SetColour(RGBA colour)
	{
		p_ECS->GetComponent<PolygonRendererComponent>(m_EntityID)->colour = colour;
	}

	void PolygonRenderer::SetLayer(int layer)
	{
		p_ECS->GetComponent<PolygonRendererComponent>(m_EntityID)->layer = layer;
	}

	Polygon PolygonRenderer::GetPolygon(Polygon polygon)
	{
		return p_ECS->GetComponent<PolygonRendererComponent>(m_EntityID)->GetPolygon();
	}

	RGBA PolygonRenderer::GetColour()
	{
		return p_ECS->GetComponent<PolygonRendererComponent>(m_EntityID)->colour;
	}

	int PolygonRenderer::GetLayer()
	{
		return p_ECS->GetComponent<PolygonRendererComponent>(m_EntityID)->layer;
	}
}
