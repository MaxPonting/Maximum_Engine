#include "Engine.h"

namespace ME
{
	
	Engine::Engine() :
		m_Window(Window()),
		m_Renderer(Renderer()),
		m_Event(SDL_Event()),
		m_Debug(Debug()),
		m_Time(EngineTime()),
		m_Running(false),
		m_EntityID(0)
	{}

	
	Engine::Engine(const char* title, const int width, const int height) :
		m_Window(Window(title, width, height)),
		m_Renderer(Renderer(m_Window)),
		m_Event(SDL_Event()),
		m_Debug(Debug(&m_Renderer)),
		m_Time(EngineTime()),
		m_Running(false),
		m_EntityID(0)
	{}

	
	void Engine::Run()
	{
		m_Running = true;

		while (m_Running)
		{
			m_Time.Update();
			UpdateEvents();
			UpdateComponents();
			UpdatePhysics();
			UpdateRenderer();
		}

		m_Renderer.SDLCleanUp();
		m_Window.SDLCleanUp();
	}

	void Engine::UpdateEvents()
	{
		while (SDL_PollEvent(&m_Event))
		{
			if (m_Event.type == SDL_QUIT)
			{
				m_Running = false;
			}
		}

		m_Time.UpdateSubFrame(EngineTime::SubFrameType::Misc);
	}

	
	void Engine::UpdateComponents()
	{
		m_Time.UpdateSubFrame(EngineTime::SubFrameType::Script);
	}

	
	void Engine::UpdatePhysics()
	{
		m_Debug.Update(m_Time);

		m_Time.UpdateSubFrame(EngineTime::SubFrameType::Physics);
	}

	
	void Engine::UpdateRenderer()
	{
		m_Renderer.Clear();

		m_Debug.Render();

		m_Renderer.Present(m_Window);

		m_Time.UpdateSubFrame(EngineTime::SubFrameType::Renderer);
	}
}