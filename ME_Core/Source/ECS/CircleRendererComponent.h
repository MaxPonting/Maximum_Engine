#pragma once

#include "Component.h"
#include "../Engine/TextureContainer.h"

namespace ME
{
	class CircleRendererComponent final : public Component
	{
	public:

		CircleRendererComponent();
		CircleRendererComponent(const unsigned int entityID, const unsigned int componentID);

		void SetRadius(float radius);
		void CreateSDLTexture(const Renderer& renderer);

		SDL_Texture* GetSDLTexture();
		unsigned int GetRadius();

		RGBA colour;
		unsigned int layer;

	private:
		
		unsigned int m_Radius;
		bool m_NewTextureNeeded;
		SDL_Texture* m_SDLTexture;

	};
}


