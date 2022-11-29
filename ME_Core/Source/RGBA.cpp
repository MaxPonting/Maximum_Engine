#include "RGBA.h"

namespace ME
{
	/* Sets to white by default */
	RGBA::RGBA() :m_Red(255), m_Green(255), m_Blue(255), m_Alpha(255) {}

	/* 
	* Sets RGBA colour parameters.
	* Makes sure RGBA values are between 0 and 255.
	*/
	RGBA::RGBA(int r, int g, int b, int a) : m_Red(r), m_Green(g), m_Blue(b), m_Alpha(a)
	{
		if (m_Red > 255) m_Red = 255;
		if (m_Green > 255) m_Green = 255;
		if (m_Blue > 255) m_Blue = 255;
		if (m_Alpha > 255) m_Alpha = 255;

		if (m_Red < 0) m_Red = 0;
		if (m_Green < 0) m_Green = 0;
		if (m_Blue < 0) m_Blue = 0;
		if (m_Alpha < 0) m_Alpha = 0;
	}

	/* Return RGBA colour parameters */
	int RGBA::GetR() const
	{
		return m_Red;
	}
	int RGBA::GetG() const
	{
		return m_Green;
	}
	int RGBA::GetB() const
	{
		return m_Blue;
	}
	int RGBA::GetA() const
	{
		return m_Alpha;
	}
}
