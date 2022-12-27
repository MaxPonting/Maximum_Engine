#pragma once

#include "../Helper/Vector2f.h"

namespace ME
{
	struct CollisionManifold
	{
		Vector2f A;
		Vector2f B;
		Vector2f Normal;
		float Depth;
		bool HasCollision;
	};
}
