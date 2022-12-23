#pragma once

#include "Component.h"
#include "../Rendering/TextureContainer.h"
#include "../Rendering/Polygon.h"

namespace ME
{
	class PolygonRendererComponent final : public Component
	{
	public:

		PolygonRendererComponent();
		PolygonRendererComponent(unsigned int entityID);

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

