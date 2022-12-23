#include "RigidbodyComponent.h"

namespace ME
{
	RigidbodyComponent::RigidbodyComponent() :
		Component(),
		Mass(1),
		GravityScale(0),
		Force(Vector2f()),
		Velocity(Vector2f())
	{}

	RigidbodyComponent::RigidbodyComponent(unsigned int entityID) :
		Component(entityID),
		Mass(1),
		GravityScale(0),
		Force(Vector2f()),
		Velocity(Vector2f())
	{}

	void RigidbodyComponent::Update(TransformComponent& transform, float deltaTime)
	{
		//
		// Apply Gravity
		//
		Force += GRAVITY * Mass * GravityScale;

		//
		// Apply Force
		//
		Velocity += (Force / Mass) * deltaTime;

		//
		// Move position
		//
		transform.position += Velocity;

		//
		// Reset Force
		//
		Force = Vector2f();
	}

	void RigidbodyComponent::AddForce(Vector2f force)
	{
		Force += force;
	}

}