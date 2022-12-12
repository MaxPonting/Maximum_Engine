#include "Engine.h"

namespace ME
{
	//
	// Default Constructor.
	//
	Engine::Engine() :
		m_Window(Window()),
		m_Renderer(Renderer()),
		m_Textures(TextureContainer()),
		m_Event(SDL_Event()),
		m_Debug(Debug()),
		m_Time(EngineTime()),
		m_Running(false)		
	{}

	//
	// Creates SDL2 window and renderer.
	//
	Engine::Engine(const char* title, const int width, const int height) :
		m_Window(Window(title, width, height)),
		m_Renderer(Renderer(m_Window)),
		m_Textures(TextureContainer(100, m_Renderer)),
		m_Event(SDL_Event()),
		m_Debug(Debug(&m_Renderer)),
		m_Time(EngineTime()),
		m_Running(false)		
	{}

	//
	// Call to start the game loop.
	// Updates components and renders textures every frame.
	// 
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

	//
	// Returns a new entity that can contain components.
	//
	Entity Engine::AddEntity()
	{
		return Entity(&m_ECS, m_ECS.AddEntity());
	}

	//
	// Destroys the entity and all its components.
	//
	void Engine::DestroyEntity(Entity entity)
	{
		m_ECS.DestroyEntity(entity.GetID());
	}

	//
	// Adds a texture to the engine using a filePath.
	// Supports PNG and JPG/JPEG files.
	//
	Texture Engine::AddTextureWithFilePath(const char* filePath)
	{
		return Texture(m_Textures.AddWithFilePath(filePath, m_Renderer)->GetID());
	}

	//
	// Polls for SDL2 events.
	// Sets running to false if the window has closed.
	//
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

	//
	// Adds each renderer component to the rendering queue.
	// Clears the renderer and then presents after rendering all objects on the queue.
	//
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