#pragma once

#include <vector>

#include "SDL.h"

#include "SDLWrapper.h"
#include "Renderer.h"


namespace ME
{
	class ContainedTexture final : public SDLWrapper
	{
	public:

		ContainedTexture();
		ContainedTexture(unsigned int m_ID, const Renderer& renderer);
		ContainedTexture(unsigned int m_ID, const char* filePath, const Renderer& renderer);

		void SDLCleanUp();

		SDL_Texture* GetSDLTexture();
		Vector2i GetSize();
		unsigned int GetID();

	private:

		SDL_Texture* p_SDLTexture;
		Vector2i m_Size;
		unsigned int m_ID;

	};

	class TextureContainer final
	{
	public:

		TextureContainer();
		TextureContainer(int reserve, const Renderer& renderer);

		ContainedTexture* operator[](const int index);

		ContainedTexture* GetWithID(const int id);

		ContainedTexture* Add(const Renderer& renderer);

		ContainedTexture* AddWithFilePath(const char* filePath, const Renderer& renderer);

		void Delete(const int index);
		
	private:

		std::vector<ContainedTexture> m_Textures;
		unsigned int m_NextTextureID;

	};
}

