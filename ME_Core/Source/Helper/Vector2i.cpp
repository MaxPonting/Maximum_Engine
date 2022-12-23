#include "Vector2i.h"
#include "Vector2f.h"

namespace ME
{
	Vector2i::Vector2i() :
		X(0),
		Y(0)
	{}

	Vector2i::Vector2i(int x, int y) :
		X(x),
		Y(y)
	{}

	Vector2i::Vector2i(Vector2f vector2) :
		X(vector2.X),
		Y(vector2.Y)
	{}

	
}
