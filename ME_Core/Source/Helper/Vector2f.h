#pragma once

#include "Vector2i.h"

namespace ME
{
	struct Vector2f final
	{
		/* CONSTRUCTORS */
		Vector2f();
		Vector2f(float x, float y);
		Vector2f(Vector2i vector2);
		
		/* MEMBERS */
		float X, Y;
	};
}


