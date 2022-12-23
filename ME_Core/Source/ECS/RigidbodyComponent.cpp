#include "RigidbodyComponent.h"

namespace ME
{
	RigidbodyComponent::RigidbodyComponent() :
		Component(),
		Mass(1),
		GravityScale(0),
		Force(Vector2f()),
		Velocity(Vector2f()),
		Torque(0),
		RotationalVelocity(0)
	{}

	RigidbodyComponent::RigidbodyComponent(unsigned int entityID) :
		Component(entityID),
		Mass(1),
		GravityScale(0),
		Force(Vector2f()),
		Velocity(Vector2f()),
		Torque(0),
		RotationalVelocity(0)
	{}

	void RigidbodyComponent::AddForce(Vector2f force)
	{
		Force += force;
	}

	void RigidbodyComponent::AddTorque(float torque)
	{
		Torque += torque;
	}

	void RigidbodyComponent::Update(TransformComponent& transform, float deltaTime)
	{
		ApplyGravity(deltaTime);
		ApplyForce(deltaTime);
		ApplyTorque(deltaTime);
		Step(transform, deltaTime);
	}

	void RigidbodyComponent::ApplyGravity(float deltaTime)
	{
		Force += GRAVITY * Mass * GravityScale;
	}

	void RigidbodyComponent::ApplyForce(float deltaTime)
	{
		Velocity += Force / Mass * deltaTime;
	}

	void RigidbodyComponent::ApplyTorque(float deltaTime)
	{
		RotationalVelocity += Torque / Mass * deltaTime;
	}

	void RigidbodyComponent::Step(TransformComponent& transform, float deltaTime)
	{
		transform.position += Velocity * deltaTime;
		transform.rotation += RotationalVelocity * deltaTime;
		Force = Vector2f();
		Torque = 0;
	}

}