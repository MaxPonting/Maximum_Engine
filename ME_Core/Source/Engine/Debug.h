#pragma once

#include <string>
#include "Sprite.h"
#include "Font.h"
#include "Renderer.h"
#include "EngineTime.h"
#include "RGBA.h"

#define NUM_DEBUG_TEXTS 7
#define UPDATE_TIME_MILLISECONDS 100
#define TEXT_COLOUR ME::RGBA(0, 255, 0, 255)
#define FONT_SIZE 18
#define FPS_TRANSFORM ME::Transform(ME::Vector2(), Angle(), ME::Vector2())

namespace ME
{
	/* Owns multiple DebugText objects to render */
	class Debug
	{
	public:

		/* CONSTRUCTOR */
		Debug();
		Debug(Renderer* renderer);		

		/* PUBLIC METHODS */
		void Update(const EngineTime& time);
		void Render();	

	private:

		/* PRIVATE CLASS */
		/* To represent text and send to renderer */
		class DebugText
		{
		public:

			/* CONSTRUCTOR */
			DebugText();
			DebugText(std::string text, Vector2i position, Font* font, const Renderer& renderer);

			/* PUBLIC METHODS */
			void SetText(const Renderer& renderer, std::string text);
			void Render(const Renderer& renderer);
		
		private:

			/* PRIVATE MEMBERS */
			std::string m_Text;
			SDL_Texture* p_Texture;
			Sprite m_Sprite;
			Vector2i m_Position;
			Font* p_Font;

		};

		/* PRIVATE MEMBERS */
		Renderer* p_Renderer;
		DebugText m_Texts[NUM_DEBUG_TEXTS];
		Font m_Font;
		float m_Timer;

	};
}


