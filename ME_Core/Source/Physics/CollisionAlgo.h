#pragma once

#include <vector>
#include "../Helper/Vector2f.h"
#include "Collision.h"
#include "ClosestPoint.h"

namespace ME
{
	class CollisionManifold;
	class ColliderComponent;
	class CircleColliderComponent;
	class RectangleColliderComponent;
	class PolygonColliderComponent;
	class TransformComponent;

	CollisionManifold GetPolygonPolygonCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const PolygonColliderComponent* polyB);
	CollisionManifold GetPolygonRectangleCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const RectangleColliderComponent* rectB);
	CollisionManifold GetPolygonCircleCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const CircleColliderComponent* circleB);
	CollisionManifold GetRectangleCircleCollisionManifold(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const CircleColliderComponent* circleB);
	CollisionManifold GetRectangleRectangleCollisionManifold(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const RectangleColliderComponent* rectB);
	CollisionManifold GetCircleCircleCollisionManifold(const TransformComponent& transformA, const CircleColliderComponent* circleA, const TransformComponent& transformB, const CircleColliderComponent* circleB);

	float AxisAlignedRectangleRectangleCollision(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const RectangleColliderComponent* rectB);
	bool AxisAlignedCircleRectangleCollision(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const CircleColliderComponent* circleB);
	bool SAT(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const PolygonColliderComponent* polyB);
	bool SATCircle(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const CircleColliderComponent* circleB);

	ClosestPoint GetLineSegmentClosestToPoint(Vector2f start, Vector2f end, Vector2f point);

	void RotateVertices(const float rotation, std::vector<Vector2f>& vertices);

	void SolveCollision(Collision collision);
	
}
