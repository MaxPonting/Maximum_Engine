#include "Debug.h"
#include "Manager.h"
#include <SDL_ttf.h>

namespace ME
{
	Debug::Debug() :
		p_Renderer(nullptr),
		m_Font(Font()),
		m_Timer(0)
	{}

	/* Creates Debug Text */
	Debug::Debug(Renderer* renderer) :
		p_Renderer(renderer),
		m_Font(Font("C:/Dev/Maximum_Engine/Assets/clear-sans.regular.ttf"))
	{
		m_Font.SetSize(FONT_SIZE);
		m_Texts[0] = DebugText("FPS:", Transform(), &m_Font, *renderer);			
		m_Texts[1] = DebugText("Frame:", Transform(Vector2(0, FONT_SIZE)), &m_Font, *renderer);
		m_Texts[2] = DebugText("Render:", Transform(Vector2(0, FONT_SIZE * 2)), &m_Font, *renderer);
		m_Texts[3] = DebugText("Physics:", Transform(Vector2(0, FONT_SIZE * 3)), &m_Font, *renderer);
		m_Texts[4] = DebugText("Scripts:", Transform(Vector2(0, FONT_SIZE * 4)), &m_Font, *renderer);
		m_Texts[5] = DebugText("Misc:", Transform(Vector2(0, FONT_SIZE * 5)), &m_Font, *renderer);
	}
	
	Debug::DebugText::DebugText() :
		m_Text(""),
		p_Font(nullptr)
	{

	}

	void Debug::Update(const EngineTime& time)
	{
		m_Timer += time.GetDeltaTime();

		if (m_Timer >= UPDATE_TIME_MILLISECONDS)
		{
			m_Texts[0].SetText(*p_Renderer, "FPS: " + std::to_string(time.GetFps()));
			m_Texts[1].SetText(*p_Renderer, "Frame: " + std::to_string(time.GetDeltaTime()).substr(0, 5) + "ms");
			m_Texts[2].SetText(*p_Renderer, "Render: " + std::to_string(time.GetRenderTime()).substr(0, 5) + "ms");
			m_Texts[3].SetText(*p_Renderer, "Physics: " + std::to_string(time.GetPhysicsTime()).substr(0, 5) + "ms");
			m_Texts[4].SetText(*p_Renderer, "Scripts: " + std::to_string(time.GetScriptTime()).substr(0, 5) + "ms");
			m_Texts[5].SetText(*p_Renderer, "Misc: " + std::to_string(time.GetMiscTime()).substr(0, 5) + "ms");

			m_Timer -= UPDATE_TIME_MILLISECONDS;
		}
		
	}

	void Debug::Render()
	{
		for (int i = 0; i < NUM_DEBUG_TEXTS; i++)
		{
			m_Texts[i].Render(*p_Renderer);
		}
	}

	Debug::DebugText::DebugText(std::string text, Transform transform, Font* font, const Renderer& renderer) :
		m_Text(text),
		m_Transform(transform),
		p_Font(font)
	{
		SetText(renderer, m_Text);
	}

	void Debug::DebugText::SetText(const Renderer& renderer, std::string text)
	{
		m_Text = text;

		if (m_Text.size() == 0) { return; }

		if (m_Texture.GetTexture() != nullptr)
		{
			m_Texture.SDLCleanUp();
		}

		const char* outputText = m_Text.c_str();
		SDL_Surface* surface;
		TTFCall(surface = TTF_RenderText_Blended(p_Font->GetFont(), outputText, SDL_Color{ 0, 255, 0, 255 }));
		
		m_Texture = Texture(renderer.CreateTextureFromSurface(surface));

		SDL_FreeSurface(surface);
		
		int w, h;
		SDL_QueryTexture(m_Texture.GetTexture(), NULL, NULL, &w, &h);

		m_Sprite = Sprite(m_Texture.GetTexture(), TEXT_COLOUR, Vector2(w, h));
	}

	void Debug::DebugText::Render(const Renderer& renderer)
	{
		renderer.RenderSprite(m_Sprite, m_Transform);
	}

	
}
