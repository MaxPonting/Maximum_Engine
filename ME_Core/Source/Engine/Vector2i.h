#pragma once

namespace ME
{
	struct Vector2f;
	struct Vector2i
	{
		/* CONSTRUCTORS */
		Vector2i();
		Vector2i(int x, int y);
		Vector2i(Vector2f vector2);

		/* MEMBERS */
		int X, Y;

	};
}


