#include "Transform.h"

namespace ME
{
	Transform::Transform() :
		Position(Vector2()),
		Rotation(0),
		Scale(Vector2())
	{}

	Transform::Transform(Vector2 pos, Angle ang, Vector2 scale) :
		Position(pos),
		Rotation(ang),
		Scale(scale)
	{}
}
