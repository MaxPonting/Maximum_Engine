#include "Font.h"
#include "Manager.h"

namespace ME
{
	Font::Font() :
		m_Font(nullptr)
	{}

	Font::Font(const char* filePath) :
		m_FilePath(filePath)
	{
		TTFCall(m_Font = TTF_OpenFont(filePath, 12));
	}

	void Font::SDLCleanUp()
	{
		TTFCall(TTF_CloseFont(m_Font));
	}

	void Font::SetSize(int size)
	{
		TTFCall(TTF_CloseFont(m_Font));
		TTFCall(m_Font = TTF_OpenFont(m_FilePath.c_str(), size));
	}

	TTF_Font* Font::GetFont()
	{
		return m_Font;
	}
}
