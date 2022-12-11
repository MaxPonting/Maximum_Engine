#include "TextureContainer.h"
#include "Manager.h"

#include <SDL_image.h>

namespace ME
{
	ContainedTexture::ContainedTexture() :
		p_SDLTexture(nullptr),
		m_ID(0)
	{}

	ContainedTexture::ContainedTexture(unsigned int m_ID, const Renderer& renderer) :
		m_ID(0),
		m_Size(Vector2(1, 1))
	{
		SDLCall(SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, 1, 1, 32, SDL_PIXELFORMAT_RGBA32));
		Uint32* buffer = (Uint32*)surface->pixels;
		
		SDLCall(SDL_LockSurface(surface));

		SDLCall(buffer[0] = SDL_MapRGBA(surface->format, 255, 255, 255, 255));

		SDLCall(SDL_UnlockSurface(surface));

		p_SDLTexture = renderer.CreateTextureFromSurface(surface);

		SDLCall(SDL_FreeSurface(surface));
	}

	ContainedTexture::ContainedTexture(unsigned int m_ID, const char* filePath, const Renderer& renderer) :
		p_SDLTexture(nullptr),
		m_ID(m_ID)
	{
		SDLCall(SDL_Surface * surface = IMG_Load(filePath));

		p_SDLTexture = renderer.CreateTextureFromSurface(surface);

		int w, h;
		SDLCall(SDL_QueryTexture(p_SDLTexture, NULL, NULL, &w, &h));

		m_Size = Vector2(w, h);

		SDLCall(SDL_FreeSurface(surface));
	}

	void ContainedTexture::SDLCleanUp()
	{
		if (p_SDLTexture == nullptr) return;

		SDLCall(SDL_DestroyTexture(p_SDLTexture));
	}

	SDL_Texture* ContainedTexture::GetSDLTexture()
	{
		return p_SDLTexture;
	}

	Vector2 ContainedTexture::GetSize()
	{
		return m_Size;
	}

	unsigned int ContainedTexture::GetID()
	{
		return m_ID;
	}

	TextureContainer::TextureContainer() :
		m_NextTextureID(-1)
	{}

	TextureContainer::TextureContainer(int reserve, const Renderer& renderer) :
		m_NextTextureID(-1)
	{
		m_Textures.reserve(reserve);
		m_Textures.emplace_back(ContainedTexture(++m_NextTextureID, renderer));
	}

	ContainedTexture* TextureContainer::operator[](const int index)
	{
		if (index >= m_Textures.size()) return nullptr;

		return &m_Textures[index];
	}

	ContainedTexture* TextureContainer::GetWithID(const int id)
	{
		for (int i = 0; i < m_Textures.size(); i++)
		{
			if (m_Textures[i].GetID() == id) return &m_Textures[i];
		}

		return nullptr;
	}

	ContainedTexture* TextureContainer::Add(const Renderer& renderer)
	{
		m_Textures.emplace_back(ContainedTexture(++m_NextTextureID, renderer));
		return &m_Textures[m_Textures.size() - 1];
	}

	ContainedTexture* TextureContainer::AddWithFilePath(const char* filePath, const Renderer& renderer)
	{
		m_Textures.emplace_back(ContainedTexture(++m_NextTextureID, filePath, renderer));
		return &m_Textures[m_Textures.size() - 1];
	}

	void TextureContainer::Delete(const int index)
	{
		if (index >= m_Textures.size()) return;

		m_Textures[index].SDLCleanUp();

		m_Textures.erase(m_Textures.begin() + index);
	}
}
