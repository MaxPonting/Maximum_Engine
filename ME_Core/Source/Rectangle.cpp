#include "Rectangle.h"

namespace ME
{
	Rectangle::Rectangle(const Renderer& renderer, int width, int height)
	{
		SDL_Surface* square = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
		Uint32* buffer = (Uint32*)square->pixels;
		int row = 0;
		int column = 0;
		int offset;
		Uint32 colour;
		SDL_LockSurface(square);

		while (row < square->w)
		{
			column = 0;
			while (column < square->h)
			{
				offset = row * square->h + column;
				colour = SDL_MapRGBA(square->format, 255, 255, 255, 255);
				buffer[offset] = colour;
				column++;
			}
			row++;
		}
		SDL_UnlockSurface(square);

		m_Texture = renderer.CreateTextureFromSurface(square);
		SDL_FreeSurface(square);
	}
}