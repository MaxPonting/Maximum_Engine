#include "SDL.h"
#include <iostream>
#include <chrono>

void Log(std::string text)
{
	std::cout << text << std::endl;
}

float deltaTime = 0;
int fps = 0;
std::chrono::time_point<std::chrono::high_resolution_clock> lastTickTime = std::chrono::high_resolution_clock::now();

void SetDelta()
{
	long delta = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() -
		std::chrono::time_point_cast<std::chrono::microseconds>(lastTickTime).time_since_epoch().count();

	double_t deltaMilliSeconds = delta * 0.001;
	deltaTime = deltaMilliSeconds;
	lastTickTime = std::chrono::high_resolution_clock::now();

	if (deltaMilliSeconds != 0) { fps = 1000 / deltaMilliSeconds; }
	else { fps = 10000; }

	std::cout << fps << std::endl;
}

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) Log(SDL_GetError());

	SDL_Window* window = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* square = SDL_CreateRGBSurfaceWithFormat(0, 1, 1, 32, SDL_PIXELFORMAT_RGBA32);	
	Uint32* buffer = (Uint32*)square->pixels;

	/*
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
	*/


	SDL_LockSurface(square);
	buffer[0] = SDL_MapRGBA(square->format, 255, 255, 255, 255);
	SDL_UnlockSurface(square);
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, square);
	SDL_FreeSurface(square);

	
	/*
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 80, 80);
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int x = 0; x < 80; x++)
	{
		for (int y = 0; y < 80; y++)
		{
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
	SDL_SetRenderTarget(renderer, 0);
	*/

	SDL_FRect rect;
	rect.x = 100; rect.y = 100;
	rect.w = 80, rect.h = 80;

	float rotation = 0;

	int x, y;

	SDL_SetTextureColorMod(texture, 255, 255, 255);
	SDL_SetTextureAlphaMod(texture, 120);

	while (true)
	{
		SetDelta();

		SDL_RenderClear(renderer);

		x = 40;
		while (x < 1200)
		{
			y = 40;
			while (y < 800)
			{
				rect.x = x; rect.y = y;
				SDL_RenderCopyExF(renderer, texture, NULL, &rect, rotation, NULL, SDL_FLIP_NONE);
				y += 120;
			}
			x += 120;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);

		rotation += 100 * deltaTime * 0.001;
	}
	
	return 0;
};