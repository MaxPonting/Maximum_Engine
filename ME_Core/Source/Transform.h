#pragma once

#include "Vector2.h"
#include "Angle.h"

namespace ME
{
	//
	// Owns a position, rotation and scale of a given entity
	//
	class Transform
	{
	public:

		/* CONSTRUCTORS */
		Transform();
		Transform(Vector2 pos);
		Transform(Vector2 pos, Vector2 scale);
		Transform(Vector2 pos, Angle ang, Vector2 scale);

		/* PUBLIC MEMBERS */
		Vector2 Position;
		Angle Rotation;
		Vector2 Scale;

	};
}


