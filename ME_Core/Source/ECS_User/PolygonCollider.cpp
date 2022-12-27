#include "PolygonCollider.h"

namespace ME
{
	void PolygonCollider::SetVertices(std::vector<Vector2f> vertices)
	{
		if (p_ECS == nullptr) return;
		PolygonColliderComponent* collider = p_ECS->GetComponent<PolygonColliderComponent>(m_EntityID);
		if (collider == nullptr) return;
		collider->Vertices = vertices;
	}

	std::vector<Vector2f> PolygonCollider::GetVertices()
	{
		if (p_ECS == nullptr) return std::vector<Vector2f>();
		PolygonColliderComponent* collider = p_ECS->GetComponent<PolygonColliderComponent>(m_EntityID);
		if (collider == nullptr) return std::vector<Vector2f>();
		return collider->Vertices;
	}
}
