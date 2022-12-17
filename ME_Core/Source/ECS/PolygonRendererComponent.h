#pragma once

#include "Component.h"
#include "../Engine/TextureContainer.h"
#include "../Polygon/Polygon.h"

namespace ME
{
	class PolygonRendererComponent final : public Component
	{
	public:

		PolygonRendererComponent();
		PolygonRendererComponent(const unsigned int entityID, const unsigned int componentID);

		void SetPolygon(Polygon polygon);
		void CreateSDLTexture(const Renderer& renderer);
	
		Polygon GetPolygon();
		SDL_Texture* GetSDLTexture();
		
		RGBA colour;
		int layer;

	private:

		Polygon m_Polygon;
		bool m_NewTextureNeeded;
		SDL_Texture* p_SDLTexture;

	};

}

