#pragma once

namespace ME
{
	class Manager final
	{
	public:

		/* STATIC METHODS */
		static void Init();
		static bool GetState();
		static bool CheckSDLError();

	private:

		/* STATIC PRIVATE MEMBERS */
		static bool s_Initialized;
	};
}

/*
	Wrapper for every SDL Call
//
	Prints a SDL error to the console
//
	Breaks if an error occurs
*/
#define SDLCall(x) x; if(ME::Manager::CheckSDLError()) __debugbreak();  

/*
	Wrapper for every TTF Call
//
	Prints a TTF error to the console
//
	Breaks if an error occurs
*/
#define TTFCall(x) x; if(ME::Manager::CheckSDLError()) __debugbreak();  

/* Defines prefix for a SDL Error */
#define SDL_Error "[SDL][Error][" + __LINE__ + "]"

/* Defines prefix for a ME Error */
#define ME_Error "[ME][Error][" + __LINE__ + "]"

/* Define prefix for ME Debug */
#define ME_Debug "[ME][Debug][" + __LINE__ + "]"

