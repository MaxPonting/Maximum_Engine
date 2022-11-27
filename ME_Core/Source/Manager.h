#pragma once

namespace ME
{
	class Manager
	{
	public:

		/* STATIC METHODS */
		static void Init();
		static bool GetState();
		static bool CheckSDLError();
		static bool CheckTTFError();

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
#define SDLCall(x) x; if(ME::Manager::CheckSDLError()) __debugbreak;  

/*
	Wrapper for every TTF Call
//
	Prints a TTF error to the console
//
	Breaks if an error occurs
*/
#define TTFCall(x) x; if(ME::Manager::CheckTTFError()) __debugbreak;  

/* Defines prefix for a ME Error */
#define ME_Error "[ME][Error]"

/* Define prefix for ME Debug */
#define ME_Debug "[ME][Debug]"

