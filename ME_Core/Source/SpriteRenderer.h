#pragma once

#include "Component.h"
#include "Renderer.h"
#include "Texture.h"
#include "RGBA.h"

namespace ME
{
	class SpriteRenderer : public Component
	{
	public:

		/* CONSTRUCTOR */
		SpriteRenderer();
		SpriteRenderer(Entity* entity, Texture* defaultTexture);

		/* PUBLIC METHODS */
 		void Render(const Renderer& renderer);

		/* SETTERS */
		void SetTexture(Texture* texture);
		void SetSize(Vector2 size);

		/* PUBLIC MEMBERS */
		RGBA colour;

	private:

		/* PRIVATE MEMBERS */
		Vector2 m_Size;
		Texture* m_Texture;
		Texture* m_DefaultTexture;
		
	};
}


