#pragma once

#include <SDL_ttf.h>
#include <string>
#include "SDLWrapper.h"

namespace ME
{
	class Font final : public SDLWrapper
	{
	public:

		Font();
		Font(const char* filePath);

		void SDLCleanUp();

		void SetSize(int size);

		TTF_Font* GetFont();

	private:

		TTF_Font* m_Font;
		std::string m_FilePath;
	};
}


