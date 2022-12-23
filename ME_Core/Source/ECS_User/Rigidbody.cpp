#include "Rigidbody.h"

ME::Rigidbody::Rigidbody() :
	ComponentRef()
{}

ME::Rigidbody::Rigidbody(unsigned int id, ECS* ecs) :
	ComponentRef(id, ecs)
{}

void ME::Rigidbody::AddForce(const Vector2f force)
{
	if (p_ECS == nullptr) return;
	RigidbodyComponent* body = p_ECS->GetComponent<RigidbodyComponent>(m_EntityID);
	if (body == nullptr) return;
	body->AddForce(force);
}

void ME::Rigidbody::AddTorque(const float torque)
{
	if (p_ECS == nullptr) return;
	RigidbodyComponent* body = p_ECS->GetComponent<RigidbodyComponent>(m_EntityID);
	if (body == nullptr) return;
	body->AddTorque(torque);
}

void ME::Rigidbody::SetMass(const float mass)
{
	if (p_ECS == nullptr) return;
	RigidbodyComponent* body = p_ECS->GetComponent<RigidbodyComponent>(m_EntityID);
	if (body == nullptr) return;
	body->Mass = mass;
}

void ME::Rigidbody::SetGravityScale(const float scale)
{
	if (p_ECS == nullptr) return;
	RigidbodyComponent* body = p_ECS->GetComponent<RigidbodyComponent>(m_EntityID);
	if (body == nullptr) return;
	body->GravityScale = scale;
}

float ME::Rigidbody::GetMass()
{
	if (p_ECS == nullptr) return 0;
	RigidbodyComponent* body = p_ECS->GetComponent<RigidbodyComponent>(m_EntityID);
	if (body == nullptr) return 0;
	return body->Mass;
}

float ME::Rigidbody::GetGravityScale()
{
	if (p_ECS == nullptr) return 0;
	RigidbodyComponent* body = p_ECS->GetComponent<RigidbodyComponent>(m_EntityID);
	if (body == nullptr) return 0;
	return body->GravityScale;
}
