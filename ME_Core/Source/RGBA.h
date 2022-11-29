#pragma once

namespace ME
{
	/* Owns RGBA colour values. */
	class RGBA
	{
	public:

		/* CONSTRUCTORS */
		RGBA();
		RGBA(int r, int g, int b, int a);

		/* GETTERS */
		int GetR() const;
		int GetG() const;
		int GetB() const;
		int GetA() const;

	private:

		/* MEMBERS */
		int m_Red, m_Green, m_Blue, m_Alpha;
	};
}


