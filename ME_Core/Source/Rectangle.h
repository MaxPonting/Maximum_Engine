#pragma once

#include "Texture.h"
#include "Renderer.h"

namespace ME
{
	class Rectangle : public Texture
	{
	public:

		/* CONSTRUCTOR */
		Rectangle(const Renderer& renderer, int width, int height);

	};
}


