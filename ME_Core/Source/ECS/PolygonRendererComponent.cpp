#include "PolygonRendererComponent.h"
#include "../Engine/Manager.h"

namespace ME
{
	PolygonRendererComponent::PolygonRendererComponent() :
		Component(),
		layer(0),
		p_SDLTexture(nullptr),
		m_NewTextureNeeded(false)
	{}

	PolygonRendererComponent::PolygonRendererComponent(unsigned int entityID) :
		Component(entityID),
		layer(0),
		p_SDLTexture(nullptr),
		m_NewTextureNeeded(true)
	{}
	
	void PolygonRendererComponent::SetPolygon(Polygon polygon)
	{
		m_Polygon = polygon;
		m_NewTextureNeeded = true;
	}

	void PolygonRendererComponent::CreateSDLTexture(const Renderer& renderer)
	{
		if (!m_NewTextureNeeded) return;

		m_NewTextureNeeded = false;

		if (p_SDLTexture != nullptr)
		{
			SDLCall(SDL_DestroyTexture(p_SDLTexture));
		}

		const unsigned int width = m_Polygon.GetWidth();
		const unsigned int height = m_Polygon.GetHeight();
		const int minX = m_Polygon.GetMinX();
		const int minY = m_Polygon.GetMinY();

		SDLCall(SDL_Surface * surface = SDL_CreateRGBSurfaceWithFormat(0, width + 1, height + 1, 32, SDL_PIXELFORMAT_RGBA32));
		Uint32* buffer = (Uint32*)surface->pixels;
		SDLCall(Uint32 colour = SDL_MapRGBA(surface->format, 255, 255, 255, 255));
		SDLCall(SDL_LockSurface(surface));
	
		std::vector<Vector2f> polygonPoints = m_Polygon.GetFilled();
		int offset;
		for (int i = 0; i < polygonPoints.size(); i++)
		{
			offset = (polygonPoints[i].Y - minY) * surface->w + (polygonPoints[i].X - minX);
			buffer[offset] = colour;
		}
	
		SDLCall(SDL_UnlockSurface(surface));
		p_SDLTexture = renderer.CreateTextureFromSurface(surface);
		SDLCall(SDL_FreeSurface(surface));
	}

	Polygon PolygonRendererComponent::GetPolygon()
	{
		return m_Polygon;
	}

	SDL_Texture* PolygonRendererComponent::GetSDLTexture()
	{
		return p_SDLTexture;
	}
}
