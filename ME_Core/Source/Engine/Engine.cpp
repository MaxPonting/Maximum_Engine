#include "Engine.h"

namespace ME
{
	
	Engine::Engine() :
		m_Window(Window()),
		m_Renderer(Renderer()),
		m_Textures(TextureContainer()),
		m_Event(SDL_Event()),
		m_Debug(Debug()),
		m_Time(EngineTime()),
		m_Running(false)		
	{}

	
	Engine::Engine(const char* title, const int width, const int height) :
		m_Window(Window(title, width, height)),
		m_Renderer(Renderer(m_Window)),
		m_Textures(TextureContainer(100, m_Renderer)),
		m_Event(SDL_Event()),
		m_Debug(Debug(&m_Renderer)),
		m_Time(EngineTime()),
		m_Running(false)		
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

	Entity Engine::AddEntity()
	{
		return Entity(&m_ECS, m_ECS.AddEntity());
	}

	void Engine::DestroyEntity(Entity entity)
	{
		m_ECS.DestroyEntity(entity.GetID());
	}

	Texture Engine::AddTextureWithFilePath(const char* filePath)
	{
		return Texture(m_Textures.AddWithFilePath(filePath, m_Renderer)->GetID());
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

		std::vector<SpriteRendererComponent*> spriteRenderers =
			m_ECS.GetComponents<SpriteRendererComponent>();

		for (int i = 0; i < spriteRenderers.size(); i++)
		{		
			TransformComponent transform = *m_ECS.GetComponent<TransformComponent>(spriteRenderers[i]->GetEntityID());
			ContainedTexture texture = *m_Textures.GetWithID(spriteRenderers[i]->texture.GetTextureID());

			m_Renderer.Enqueue({
				transform,
				Sprite(texture.GetSDLTexture(), spriteRenderers[i]->colour, texture.GetSize()),
				spriteRenderers[i]->layer
			});
		}

		std::vector<CircleRendererComponent*> circleRenderers =
			m_ECS.GetComponents<CircleRendererComponent>();

		for (int i = 0; i < circleRenderers.size(); i++)
		{
			circleRenderers[i]->CreateSDLTexture(m_Renderer);

			TransformComponent transform = *m_ECS.GetComponent<TransformComponent>(circleRenderers[i]->GetEntityID());
			int radius = circleRenderers[i]->GetRadius();

			m_Renderer.Enqueue({
				transform,
				Sprite(circleRenderers[i]->GetSDLTexture(), circleRenderers[i]->colour, Vector2(radius * 2, radius * 2)),
				circleRenderers[i]->layer
			});
		}

		m_Renderer.RenderQueue();

		m_Debug.Render();

		m_Renderer.Present(m_Window);

		m_Time.UpdateSubFrame(EngineTime::SubFrameType::Renderer);
	}
}