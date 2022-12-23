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

		//
		// Operators
		//
		void operator=(const Vector2f vector2);
		void operator+=(const Vector2f vector2);
		void operator-=(const Vector2f vector2);
		Vector2f operator+(const Vector2f vector2);		
		Vector2f operator-(const Vector2f vector2);
		Vector2f operator*(const Vector2f vector2);
		Vector2f operator*(const float scale);
		Vector2f operator/(const Vector2f vector2);
		Vector2f operator/(const float scale);
		
		/* MEMBERS */
		float X, Y;
	};
}


