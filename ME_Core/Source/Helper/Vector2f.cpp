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

	void Vector2f::operator=(const Vector2f vector2)
	{
		X = vector2.X; Y = vector2.Y;
	}

	void Vector2f::operator+=(const Vector2f vector2)
	{
		X += vector2.X; Y += vector2.Y;
	}

	void Vector2f::operator-=(const Vector2f vector2)
	{
		X -= vector2.X; Y -= vector2.Y;
	}

	Vector2f Vector2f::operator+(const Vector2f vector2)
	{
		return Vector2f(X + vector2.X, Y + vector2.Y);
	}

	Vector2f Vector2f::operator-(const Vector2f vector2)
	{
		return Vector2f(X - vector2.X, Y - vector2.Y);
	}

	Vector2f Vector2f::operator*(const Vector2f vector2)
	{
		return Vector2f(X * vector2.X, Y * vector2.Y);
	}

	Vector2f Vector2f::operator*(const float scale)
	{
		return Vector2f(X * scale, Y * scale);
	}

	Vector2f Vector2f::operator/(const Vector2f vector2)
	{
		return Vector2f(X / vector2.X, Y / vector2.Y);
	}

	Vector2f Vector2f::operator/(const float scale)
	{
		return Vector2f(X / scale, Y / scale);
	}

}