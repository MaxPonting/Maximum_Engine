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
		m_Fonts(FontContainer()),
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
		m_Fonts(FontContainer(10)),
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
	Texture Engine::AddTexture(const char* filePath)
	{
		return Texture(m_Textures.Add(filePath, m_Renderer)->GetID());
	}

	//
	// Adds a font to the engine using a filePath.
	// Supports TTF files.
	//
	Font Engine::AddFont(const char* filePath)
	{
		return Font(m_Fonts.Add(filePath)->GetID());
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

		//
		// Add sprites to the render queue
		//
		std::vector<SpriteRendererComponent>* spriteRenderers =
			m_ECS.GetComponents<SpriteRendererComponent>();

		SpriteRendererComponent spriteRenderer;

		for (int i = 0; i < spriteRenderers->size(); i++)
		{		
			spriteRenderer = spriteRenderers->operator[](i);
			TransformComponent transform = *m_ECS.GetComponent<TransformComponent>(spriteRenderer.GetEntityID());
			ContainedTexture texture = *m_Textures.GetWithID(spriteRenderer.texture.GetTextureID());

			m_Renderer.Enqueue({
				transform,
				Sprite(texture.GetSDLTexture(), spriteRenderer.colour, texture.GetSize()),
				spriteRenderer.layer
			});
		}

		//
		// Add circles to the render queue
		//
		std::vector<CircleRendererComponent>* circleRenderers =
			m_ECS.GetComponents<CircleRendererComponent>();

		CircleRendererComponent circleRenderer;

		for (int i = 0; i < circleRenderers->size(); i++)
		{
			circleRenderers->operator[](i).CreateSDLTexture(m_Renderer);
			circleRenderer = circleRenderers->operator[](i);

			TransformComponent transform = *m_ECS.GetComponent<TransformComponent>(circleRenderer.GetEntityID());
			int radius = circleRenderer.GetRadius();

			m_Renderer.Enqueue({
				transform,
				Sprite(circleRenderer.GetSDLTexture(), circleRenderer.colour, Vector2i(radius * 2, radius * 2)),
				circleRenderer.layer
			});
		}

		//
		// Add polygons to the render queue
		//
		std::vector<PolygonRendererComponent>* polygonRenderers =
			m_ECS.GetComponents<PolygonRendererComponent>();

		PolygonRendererComponent polygonRenderer;
		
		for (int i = 0; i < polygonRenderers->size(); i++)
		{
			polygonRenderers->operator[](i).CreateSDLTexture(m_Renderer);
			polygonRenderer = polygonRenderers->operator[](i);

			TransformComponent transform = *m_ECS.GetComponent<TransformComponent>(polygonRenderer.GetEntityID());
			
			Vector2i size = Vector2i(polygonRenderer.GetPolygon().GetWidth(), polygonRenderer.GetPolygon().GetHeight());
			m_Renderer.Enqueue({
				transform,
				Sprite(polygonRenderer.GetSDLTexture(), polygonRenderer.colour, size),
				polygonRenderer.layer
			});
		}

		//
		// Add text to the render queue
		//
		std::vector<TextRendererComponent>* textRenderers =
			m_ECS.GetComponents<TextRendererComponent>();

		TextRendererComponent textRenderer;

		for (int i = 0; i < textRenderers->size(); i++)
		{
			std::string filePath = m_Fonts.GetWithID(textRenderers->operator[](i).font.GetFontID())->GetFilePath();

			if (filePath.size() != 0)
			{
				textRenderers->operator[](i).CreateSDLTexture(m_Renderer, filePath.c_str());
				textRenderer = textRenderers->operator[](i);

				TransformComponent transform = *m_ECS.GetComponent<TransformComponent>(textRenderer.GetEntityID());

				m_Renderer.Enqueue({
					transform,
					Sprite(textRenderer.GetSDLTexture(), textRenderer.colour, textRenderer.GetTextureSize()),
					textRenderer.layer
				});
			}			
		}

		m_Renderer.RenderQueue();

		m_Debug.Render();

		m_Renderer.Present(m_Window);

		m_Time.UpdateSubFrame(EngineTime::SubFrameType::Renderer);
	}

}