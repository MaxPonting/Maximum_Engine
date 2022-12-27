#pragma once

#include <vector>

#include "Collider.h"

namespace ME
{
	class PolygonCollider : public Collider
	{
	public:

		using Collider::Collider;

		void SetVertices(std::vector<Vector2f> vertices);

		std::vector<Vector2f> GetVertices();

	};
}


