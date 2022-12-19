#pragma once

namespace ME
{
	class Angle final
	{
	public:

		/* CONSTRUCTORS */
		Angle();
		Angle(float angle);

		/* OPERATORS */
		void operator=(float angle);
		Angle operator+(float degrees);
		bool operator==(Angle angle);
		
		/* GETTERS */
		float getDeg() const;
		float getRad() const;

	private:

		/* PRIVATE MEMBERS */
		float m_degrees;
	};
}


