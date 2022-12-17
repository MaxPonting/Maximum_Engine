#include "Vector2f.h"

namespace ME
{
	Vector2f::Vector2f() :
		X(0),
		Y(0)
	{}

	Vector2f::Vector2f(float x, float y) :
		X(x),
		Y(y)
	{}

	Vector2f::Vector2f(Vector2i vector2) :
		X(vector2.X),
		Y(vector2.Y)
	{}

}