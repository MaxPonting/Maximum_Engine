#pragma once

namespace ME
{
	class Vector2
	{
	public:

		/* CONSTRUCTORS */
		Vector2();
		Vector2(float x, float y);

		/* GETTERS */
		float GetX() const;
		float GetY() const;

	private:

		/* PRIVATE MEMBERS */
		float m_X, m_Y;

	};
}


