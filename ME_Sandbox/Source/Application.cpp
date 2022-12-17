#include <ME.h>

int main(int argc, char* args[])
{
	ME::Manager::Init();
	ME::Engine engine = ME::Engine("Sandbox", 1280, 720);

	ME::Entity entity = engine.AddEntity();
	ME::Entity entity2 = engine.AddEntity();
	ME::Entity entity3 = engine.AddEntity();

	ME::Texture texture = engine.AddTextureWithFilePath("../Assets/PNGs/Sword.png");

	ME::Transform transform = entity.GetComponent<ME::Transform>();
	ME::SpriteRenderer spriteRenderer = entity.AddComponent<ME::SpriteRenderer>();	
	transform.SetPosition(ME::Vector2f(100, 550));
	spriteRenderer.SetTexture(texture);
	spriteRenderer.SetLayer(3);

	ME::Transform transform2 = entity2.GetComponent<ME::Transform>();
	ME::PolygonRenderer polygonRenderer = entity2.AddComponent<ME::PolygonRenderer>();
	transform2.SetPosition(ME::Vector2f(100, 200));
	transform2.SetScale(ME::Vector2f(1, 1));
	polygonRenderer.SetPolygon(ME::Polygon({ { 0, -200 }, { 150, 100 }, { -150, 100 }, {-125, -125} }));
	polygonRenderer.SetLayer(2);
	
	ME::Transform transform3 = entity3.GetComponent<ME::Transform>();
	ME::CircleRenderer renderer3 = entity3.AddComponent<ME::CircleRenderer>();
	transform3.SetPosition(ME::Vector2f(500, 50));
	transform3.SetScale(ME::Vector2f(1, 1));
	renderer3.SetRadius(200);
	renderer3.SetColour(ME::RGBA(255, 0, 0, 255));
	renderer3.SetLayer(2);
	
	engine.Run();

	return 0;
}
