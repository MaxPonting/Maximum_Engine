#include "CollisionAlgo.h"
#include "CollisionManifold.h"
#include "ClosestPoint.h"
#include "../ECS/CircleColliderComponent.h"
#include "../ECS/RectangleColliderComponent.h"
#include "../ECS/TransformComponent.h"
#include "../Helper/Vector2f.h"

namespace ME
{
	CollisionManifold GetPolygonPolygonCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const PolygonColliderComponent* polyB)
	{
		// Check for collision
		bool collision = SAT(transformA, polyA, transformB, polyB);

		CollisionManifold manifold;
		manifold.HasCollision = collision;

		// Return if no collision
		if (!collision) return manifold;

		// Set Collision manifold
		manifold.Depth = 0;
		manifold.Normal = Vector2f();
		manifold.A = Vector2f();
		manifold.B = Vector2f();

		return manifold;
	}

	CollisionManifold GetPolygonRectangleCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const RectangleColliderComponent* rectB)
	{
		return CollisionManifold();
	}

	CollisionManifold GetPolygonCircleCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		// Check for collision
		bool collision = SATCircle(transformA, polyA, transformB, circleB);

		CollisionManifold manifold;
		manifold.HasCollision = collision;

		// Return if no collision
		if (!collision) return manifold;

		// Set Collision manifold
		manifold.Depth = 0;
		manifold.Normal = Vector2f();
		manifold.A = Vector2f();
		manifold.B = Vector2f();

		return manifold;
	}

	CollisionManifold GetRectangleRectangleCollisionManifold(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const RectangleColliderComponent* rectB)
	{
		// Check for collision
		bool depth;

		if (transformA.rotation.getDeg() == 0)
			depth = AxisAlignedRectangleRectangleCollision(transformA, rectA, transformB, rectB);
		else
			depth = 0;

		CollisionManifold manifold;
		manifold.HasCollision = depth > 0;

		// Return if no collision
		if (!manifold.HasCollision) return manifold;

		// Find the closest point on the rect B to the center of A
		std::vector<Vector2f> VerticesB = rectB->GetVertices(transformB);

		ClosestPoint closestPointA = GetLineSegmentClosestToPoint(
			VerticesB[VerticesB.size() - 1],
			VerticesB[0],
			transformA.position
		);

		int j = 0;
		for (int i = 1; i < VerticesB.size(); i++)
		{
			ClosestPoint point = GetLineSegmentClosestToPoint(
				VerticesB[j], 
				VerticesB[i],
				transformA.position
			);
			if (point.Distance < closestPointA.Distance) closestPointA = point;
			j = i;
		}

		// Find the closest point on the rect A to the center of B
		std::vector<Vector2f> VerticesA = rectA->GetVertices(transformA);

		ClosestPoint closestPointB = GetLineSegmentClosestToPoint(
			VerticesA[VerticesA.size() - 1],
			VerticesA[0],
			transformB.position
		);

		j = 0;
		for (int i = 1; i < VerticesA.size(); i++)
		{
			ClosestPoint point = GetLineSegmentClosestToPoint(
				VerticesA[j], 
				VerticesA[i],
				transformB.position
			);
			if (point.Distance < closestPointB.Distance) closestPointB = point;
			j = i;
		}


		// Set Collision manifold
		manifold.A = closestPointA.Point;
		manifold.B = closestPointB.Point;
		manifold.Depth = depth;
		manifold.Normal = manifold.B - manifold.A;

		return manifold;
	}

	CollisionManifold GetRectangleCircleCollisionManifold(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		// Check for collision
		bool collision;

		if (transformA.rotation.getDeg() == 0)
			collision = AxisAlignedCircleRectangleCollision(transformA, rectA, transformB, circleB);
		else
			collision = false;

		CollisionManifold manifold;
		manifold.HasCollision = collision;

		// Return if no collision
		if (!collision) return manifold;
		
		// Find the closest point on the rect A to the center of B
		std::vector<Vector2f> Vertices = rectA->GetVertices(transformA);

		ClosestPoint closestPointB = GetLineSegmentClosestToPoint(
			Vertices[Vertices.size() - 1],
			Vertices[0],
			transformB.position
		);

		int j = 0;
		for (int i = 1; i < Vertices.size(); i++)
		{
			ClosestPoint point = GetLineSegmentClosestToPoint(
				Vertices[j], 
				Vertices[i],
				transformB.position
			);
			if (point.Distance < closestPointB.Distance) closestPointB = point;
			j = i;
		}

		// Find the closest point on the cirlce B to the center of A
		ClosestPoint closestPointA;

		Vector2f BToClosestBDir = (closestPointB.Point - transformB.position).Normalize();
		closestPointA.Point = transformB.position + BToClosestBDir * circleB->Radius;

		// Set Collision manifold
		manifold.A = closestPointA.Point;
		manifold.B = closestPointB.Point;
		manifold.Depth = (manifold.B - manifold.A).Magnitude() / 2;
		manifold.Normal = (manifold.B - manifold.A).Normalize();
		
		return manifold;
	}

	CollisionManifold GetCircleCircleCollisionManifold(const TransformComponent& transformA, const CircleColliderComponent* circleA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		// Check for collision
		Vector2f heading = transformB.position - transformA.position;
		float distance = pow(heading.X * heading.X + heading.Y * heading.Y, 0.5);
		bool collision = distance <= circleA->Radius + circleB->Radius;

		CollisionManifold manifold;
		manifold.HasCollision = collision;

		// Return if no collision
		if (!collision) return manifold;

		// Set Collision manifold
		manifold.Depth = (circleA->Radius + circleB->Radius - distance + 0.001) / 2;
		manifold.Normal = heading.Normalize();
		manifold.A = transformA.position + manifold.Normal * (circleA->Radius - manifold.Depth * 2);
		manifold.B = transformB.position - manifold.Normal * (circleB->Radius - manifold.Depth * 2);

		return manifold;
	}

	
	float AxisAlignedRectangleRectangleCollision(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const RectangleColliderComponent* rectB)
	{
		if (abs(transformA.position.X - transformB.position.X) > (rectA->Width / 2 + rectB->Width / 2)) return 0;
		if (abs(transformA.position.Y - transformB.position.Y) > (rectA->Height / 2 + rectB->Height / 2)) return 0;

		float depthX = rectA->Width / 2 + rectB->Width / 2 - transformA.position.X - transformB.position.X;
		float depthY = rectA->Height / 2 + rectB->Height / 2 - transformA.position.Y - transformB.position.Y;

		if (depthX < depthY) return depthX;
		return depthY;
	}

	bool AxisAlignedCircleRectangleCollision(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		float dx = abs(transformB.position.X - transformA.position.X) - rectA->Width / 2;
		float dy = abs(transformB.position.Y - transformA.position.Y) - rectA->Height / 2;

		if (dx > circleB->Radius || dy > circleB->Radius ) return false;
		if (dx <= 0 || dy <= 0) return true;

		return (dx * dx + dy * dy <= circleB->Radius * circleB->Radius);
	}

	bool SAT(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const PolygonColliderComponent* polyB)
	{
		return false;
	}

	bool SATCircle(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		return false;
	}
	
	ClosestPoint GetLineSegmentClosestToPoint(Vector2f A, Vector2f B, Vector2f P)
	{
		Vector2f AB = B - A;
		Vector2f AP = P - A;

		float projection = AP * AB;
		float ABLengthSqr = AB.LengthSqr();
		float D = projection / ABLengthSqr;

		ClosestPoint closestPoint;

		if (D <= 0) closestPoint.Point = A;
		else if (D >= 1) closestPoint.Point = B;
		else closestPoint.Point = A + AB * D;
			 
		closestPoint.Distance = (P - closestPoint.Point).Magnitude();

		return closestPoint;
	}

	void RotateVertices(const float rotation, std::vector<Vector2f>& vertices)
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			Vector2f rotatedVector;
			rotatedVector.X = vertices[i].X * cos(rotation) - sin(rotation) * vertices[i].Y;
			rotatedVector.Y = vertices[i].X * sin(rotation) + cos(rotation) * vertices[i].Y;
			vertices[i] = rotatedVector;
		}
	}
	
	void SolveCollision(Collision collision)
	{
		// Seperate bodies
		// A

		Vector2f directionA = (collision.TransformA.position - collision.Manifold.A).Normalize();
		Vector2f transformationA = directionA * collision.Manifold.Depth;
		collision.TransformA.position += transformationA;

		// B

		Vector2f directionB = (collision.TransformB.position - collision.Manifold.B).Normalize();
		Vector2f transformationB = directionB * collision.Manifold.Depth;
		collision.TransformB.position += transformationB;

		// Apply Impulse


	}
}