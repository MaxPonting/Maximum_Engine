#include "PolygonRendererComponent.h"

namespace ME
{
	PolygonRendererComponent::PolygonRendererComponent() :
		Component(),
		layer(0),
		p_SDLTexture(nullptr),
		m_NewTextureNeeded(false)
	{}

	PolygonRendererComponent::PolygonRendererComponent(const unsigned int entityID, const unsigned int componentID) :
		Component(entityID, componentID),
		layer(0),
		p_SDLTexture(nullptr),
		m_NewTextureNeeded(true)
	{}

	void PolygonRendererComponent::SetVertices(std::vector<Vector2> vertices)
	{
		m_Vertices = vertices;
		m_NewTextureNeeded = true;
	}

	void PolygonRendererComponent::CreateSDLTexture(const Renderer& renderer)
	{

	}

	std::vector<Vector2> PolygonRendererComponent::GetFilledPolygon()
	{
		std::vector<Vector2> points;
		return points;
		
	}

	std::vector<Vector2> PolygonRendererComponent::GetVertices()
	{
		return m_Vertices;
	}

	SDL_Texture* PolygonRendererComponent::GetSDLTexture()
	{
		return p_SDLTexture;
	}
}
