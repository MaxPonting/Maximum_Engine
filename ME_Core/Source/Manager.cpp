
/* C++ */
#include <string>

/* SDL2 */
#include <SDL.h>
#include <SDL_ttf.h>

/* ME */
#include "Manager.h"
#include "Log.h"

namespace ME
{
	bool Manager::s_Initialized = false;

	/* Init SDL2 */
	void Manager::Init()
	{
		SDLCall(SDL_Init(SDL_INIT_VIDEO));
		TTFCall(TTF_Init());
		s_Initialized = true;
	}

	bool Manager::GetState()
	{
		return s_Initialized;
	}

	/*
		Check if a SDL2 error occurs
	//
		Prints error to the console
	*/
	bool Manager::CheckSDLError()
	{
		std::string error = SDL_GetError();
		SDL_ClearError();
		if (error.size() == 0)
		{
			return false;
		}
		else
		{
			Log::PrintToLog("[SDL][Error]", error);
			return true;
		}
	}

	/*
		Check if a TTF error occurs
	//
		Prints error to the console
	*/
	bool Manager::CheckTTFError()
	{
		std::string error = TTF_GetError();
		if (error.size() == 0)
		{
			return false;
		}
		else
		{
			Log::PrintToLog("[TTF][Error]", error);
			return true;
		}
	}
}
