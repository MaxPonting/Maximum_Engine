#pragma once

#include <vector>

#include "../Engine/Vector2i.h"
#include "Scanline.h"

namespace ME
{
	class Polygon final
	{
	public:

		Polygon();
		Polygon(std::vector<Vector2f> vertices);

		unsigned int GetWidth();
		unsigned int GetHeight();
		int GetMinX();
		int GetMinY();
		std::vector<Vector2f> GetFilled();

	private:

		std::vector<Vector2f> m_Vertices;
	
	};
}

