#include "Transform.h"

namespace ME
{
	Transform::Transform() : ComponentRef() {}
	Transform::Transform(unsigned int entityID, ECS* ecs) : ComponentRef(entityID, ecs) {}

	void Transform::SetPosition(Vector2 position)
	{
		p_ECS->GetComponent<TransformComponent>(m_EntityID)->position = position;
	}

	void Transform::SetRotation(float rotation)
	{
		p_ECS->GetComponent<TransformComponent>(m_EntityID)->rotation = rotation;
	}

	void Transform::SetScale(Vector2 scale)
	{
		p_ECS->GetComponent<TransformComponent>(m_EntityID)->scale = scale;
	}

	Vector2 Transform::GetPosition()
	{
		return p_ECS->GetComponent<TransformComponent>(m_EntityID)->position;
	}

	float Transform::GetRotation()
	{
		return p_ECS->GetComponent<TransformComponent>(m_EntityID)->rotation.getDeg();
	}

	Vector2 Transform::GetScale()
	{
		return p_ECS->GetComponent<TransformComponent>(m_EntityID)->scale;
	}
}
