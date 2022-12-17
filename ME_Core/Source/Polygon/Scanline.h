#pragma once

#include <vector>

#include "../Engine/Vector2i.h"
#include "../Engine/Vector2f.h"

namespace ME
{
	std::vector<Vector2f> Scanline(std::vector<Vector2f> verts, unsigned int w, unsigned int h);

	void AssignMinMaxXY(std::vector<Vector2f> verts, float& minX, float& maxX, float& minY, float& maxY);
}
