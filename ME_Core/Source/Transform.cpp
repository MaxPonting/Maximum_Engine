#include "Transform.h"

namespace ME
{
	Transform::Transform() :
		Position(Vector2()),
		Rotation(0),
		Scale(Vector2(1, 1))
	{}

	Transform::Transform(Vector2 pos) :
		Position(pos),
		Rotation(0),
		Scale(Vector2(1, 1))
	{}

	Transform::Transform(Vector2 pos, Vector2 scale) :
		Position(pos),
		Rotation(0),
		Scale(scale)
	{}

	Transform::Transform(Vector2 pos, Angle ang, Vector2 scale) :
		Position(pos),
		Rotation(ang),
		Scale(scale)
	{}
}
