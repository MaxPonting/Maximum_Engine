#pragma once

#include "Component.h"
#include "../Engine/TextureContainer.h"


namespace ME
{
	class PolygonRendererComponent final : public Component
	{
	public:

		PolygonRendererComponent();
		PolygonRendererComponent(const unsigned int entityID, const unsigned int componentID);

		void SetVertices(std::vector<Vector2> vertices);
		void CreateSDLTexture(const Renderer& renderer);

		std::vector<Vector2> GetVertices();
		SDL_Texture* GetSDLTexture();
		

		RGBA colour;
		unsigned int layer;

	private:

		std::vector<Vector2> GetFilledPolygon();

		std::vector<Vector2> m_Vertices;
		bool m_NewTextureNeeded;
		SDL_Texture* p_SDLTexture;

	};

}

