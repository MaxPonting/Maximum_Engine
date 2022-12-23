#include "Polygon.h"

namespace ME
{
	Polygon::Polygon()
	{
		m_Vertices =
		{
			{  10,  10 },
			{ -10,  10 },
			{ -10, -10 },
			{  10, -10 }
		};
	}

	Polygon::Polygon(std::vector<Vector2f> vertices) :
		m_Vertices(vertices)
	{}

	unsigned int Polygon::GetWidth()
	{
		// Return 0 if vertices size is 2 or less
		if (m_Vertices.size() <= 2) return 0;

		int xMin = m_Vertices[0].X;
		int xMax = xMin;

		for (int i = 1; i < m_Vertices.size(); i++)
		{
			if (m_Vertices[i].X < xMin) xMin = m_Vertices[i].X;
			if (m_Vertices[i].X > xMax) xMax = m_Vertices[i].X;
		}

		return xMax - xMin;
	}

	unsigned int Polygon::GetHeight()
	{
		// Return 0 if vertices size is 2 or less
		if (m_Vertices.size() <= 2) return 0;

		int yMin = m_Vertices[0].Y;
		int yMax = yMin;

		for (int i = 1; i < m_Vertices.size(); i++)
		{
			if (m_Vertices[i].Y < yMin) yMin = m_Vertices[i].Y;
			if (m_Vertices[i].Y > yMax) yMax = m_Vertices[i].Y;
		}

		return yMax - yMin;
	}

	int Polygon::GetMinX()
	{
		// Return 0 if vertices size is 2 or less
		if (m_Vertices.size() <= 2) return 0;

		int minX = m_Vertices[0].X;

		for (int i = 1; i < m_Vertices.size(); i++)
		{
			if (m_Vertices[i].X < minX) minX = m_Vertices[i].X;
		}

		return minX;
	}

	int Polygon::GetMinY()
	{
		// Return 0 if vertices size is 2 or less
		if (m_Vertices.size() <= 2) return 0;

		int minY = m_Vertices[0].Y;

		for (int i = 1; i < m_Vertices.size(); i++)
		{
			if (m_Vertices[i].Y < minY) minY = m_Vertices[i].Y;
		}

		return minY;
	}

	std::vector<Vector2f> Polygon::GetFilled()
	{
		return Scanline(m_Vertices, GetWidth(), GetHeight());
	}
	
}
