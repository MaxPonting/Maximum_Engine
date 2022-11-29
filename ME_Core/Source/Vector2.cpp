#include "Vector2.h"

namespace ME
{
	Vector2::Vector2() :
		m_X(0),
		m_Y(0)
	{}
	
	Vector2::Vector2(float x, float y) :
		m_X(x),
		m_Y(y)
	{}

	float Vector2::GetX() const
	{
		return m_X;
	}

	float Vector2::GetY() const
	{
		return m_Y;
	}
}
