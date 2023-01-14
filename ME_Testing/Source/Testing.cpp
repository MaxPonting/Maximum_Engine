
#include "SDL.h"
#include <iostream>
#include <chrono>
#include <math.h>

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

	//std::cout << fps << std::endl;
}

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) Log(SDL_GetError());

	SDL_Window* window = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int radius = 350;
	SDL_Surface* square = SDL_CreateRGBSurfaceWithFormat(0, radius * 2, radius * 2, 32, SDL_PIXELFORMAT_RGBA32);	
	Uint32* buffer = (Uint32*)square->pixels;

	int radius2 = radius * radius;
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
			int dx = radius - row;
			int dy = radius - column;
			if (dx*dx + dy*dy < radius2)
			{
				offset = row * square->h + column;
				colour = SDL_MapRGBA(square->format, 255, 255, 255, 255);
				buffer[offset] = colour;
				
			}
			column++;
		}
		row++;
	}
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

	SDL_Rect rect;
	rect.x = 260; rect.y = 10;
	rect.w = radius * 2, rect.h = radius * 2;

	float xPosition = 0;
	bool left = true;
	int x, y;

	SDL_SetTextureColorMod(texture, 255, 120, 120);
	SDL_SetTextureAlphaMod(texture, 255);

	while (true)
	{
		SetDelta();

		SDL_RenderClear(renderer);

		rect.x = xPosition;
		SDL_RenderCopy(renderer, texture, NULL, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);

		if (left)
		{
			xPosition += 600 * deltaTime * 0.001;
			if (xPosition >= 1280 - radius * 2)
			{
				left = false;
			}
		}
		else
		{
			xPosition -= 600 * deltaTime * 0.001;
			if (xPosition < 0)
			{
				left = true;
			}
		}
		
	}
	
	return 0;
};