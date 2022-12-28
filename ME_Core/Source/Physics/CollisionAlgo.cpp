#include "CollisionAlgo.h"
#include "CollisionManifold.h"
#include "../ECS/CircleColliderComponent.h"
#include "../ECS/RectangleColliderComponent.h"
#include "../ECS/PolygonColliderComponent.h"
#include "../ECS/TransformComponent.h"
#include "../Helper/Vector2f.h"
#include "../Helper/Edge.h"

namespace ME
{
	CollisionManifold GetPolygonPolygonCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const PolygonColliderComponent* polyB)
	{
		// Check for collision

		CollisionManifold manifold = SAT(transformA, polyA->GetVertices(transformA), transformB, polyB->GetVertices(transformB));

		return manifold;
	}

	CollisionManifold GetPolygonRectangleCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const RectangleColliderComponent* rectB)
	{
		return CollisionManifold();
	}

	CollisionManifold GetPolygonCircleCollisionManifold(const TransformComponent& transformA, const PolygonColliderComponent* polyA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		// Check for collision
		CollisionManifold manifold = SATCircle(transformA, polyA->GetVertices(transformA), transformB, circleB);

		return manifold;
	}

	CollisionManifold GetRectangleRectangleCollisionManifold(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const RectangleColliderComponent* rectB)
	{
		// Check for collision
		CollisionManifold manifold;

		if (transformA.rotation.getDeg() == transformB.rotation.getDeg())
			manifold = AxisAlignedRectangleRectangleCollision(transformA, rectA, transformB, rectB);
		else
			manifold = CollisionManifold();

		return manifold;
	}

	CollisionManifold GetRectangleCircleCollisionManifold(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		// Check for collision
		CollisionManifold manifold;

		if (transformA.rotation.getDeg() == 0)
			manifold = AxisAlignedCircleRectangleCollision(transformA, rectA, transformB, circleB);
		else
			manifold = CollisionManifold();
		
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
		manifold.Depth = (circleA->Radius + circleB->Radius - distance) / 2;
		manifold.Normal = heading.Normalize();

		return manifold;
	}

	
	CollisionManifold AxisAlignedRectangleRectangleCollision(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const RectangleColliderComponent* rectB)
	{
		if (abs(transformA.position.X - transformB.position.X) > (rectA->Width / 2 + rectB->Width / 2)) return CollisionManifold();
		if (abs(transformA.position.Y - transformB.position.Y) > (rectA->Height / 2 + rectB->Height / 2)) return CollisionManifold();

		CollisionManifold manifold;
		manifold.HasCollision = true;

		float depthX = rectA->Width / 2 + rectB->Width / 2 - abs(transformA.position.X - transformB.position.X);
		float depthY = rectA->Height / 2 + rectB->Height / 2 - abs(transformA.position.Y - transformB.position.Y);

		if (depthX < depthY)
		{
			manifold.Depth = depthX / 2 + 0.001f;
			if (transformA.position.X > transformB.position.X) manifold.Normal = { -1, 0 };
			else manifold.Normal = { 1, 0 };		
		}
		else
		{
			manifold.Depth = depthY / 2 + 0.001f;
			if (transformA.position.Y > transformB.position.Y) manifold.Normal = { 0, -1 };
			else manifold.Normal = { 0, 1 };			
		}

		return manifold;
	}

	CollisionManifold AxisAlignedCircleRectangleCollision(const TransformComponent& transformA, const RectangleColliderComponent* rectA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		float px = transformB.position.X;
		float py = transformB.position.Y;
		px = fmaxf(px, transformA.position.X - rectA->Width / 2);
		px = fminf(px, transformA.position.X + rectA->Width / 2);
		py = fmaxf(py, transformA.position.Y - rectA->Height / 2);
		py = fminf(py, transformA.position.Y + rectA->Height / 2);

		Vector2f heading = { px - transformB.position.X, py - transformB.position.Y };
		float distanceSqr = heading.LengthSqr();

		CollisionManifold manifold;		

		if (distanceSqr >= circleB->Radius * circleB->Radius) manifold.HasCollision = false;

		if (!manifold.HasCollision) return manifold;

		float distance = pow(distanceSqr, 0.5);
		manifold.Normal = heading.Normalize(distance);
		manifold.Depth = (circleB->Radius - distance) / 2;

		return manifold;
	}

	CollisionManifold SAT(const TransformComponent& transformA, const std::vector<Vector2f>& verticesA, const TransformComponent& transformB, const std::vector<Vector2f>& verticesB)
	{
		int j = verticesA.size() - 1;
		for (int i = 0; i < verticesA.size(); i++)
		{
			Vector2f edge = verticesA[j] - verticesA[i];
			Vector2f axis = Vector2f(-edge.Y, edge.X);

			float minA, maxA;
			float minB, maxB;

			ProjectVertices(verticesA, axis, minA, maxA);
			ProjectVertices(verticesB, axis, minB, maxB);

			if (minA >= maxB || minB >= maxA) return CollisionManifold();

			j = i;
		}

		j = verticesB.size() - 1;
		for (int i = 0; i < verticesB.size(); i++)
		{
			Vector2f edge = verticesB[j] - verticesB[i];
			Vector2f axis = Vector2f(-edge.Y, edge.X);

			float minA, maxA;
			float minB, maxB;

			ProjectVertices(verticesA, axis, minA, maxA);
			ProjectVertices(verticesB, axis, minB, maxB);

			if (minA >= maxB || minB >= maxA) return CollisionManifold();

			j = i;
		}

		CollisionManifold manifold;

		manifold.HasCollision = true;

		return manifold;
	}

	CollisionManifold SATCircle(const TransformComponent& transformA, const std::vector<Vector2f>& verticesA, const TransformComponent& transformB, const CircleColliderComponent* circleB)
	{
		return CollisionManifold();
	}

	void ProjectVertices(const std::vector<Vector2f>& vertices, const Vector2f& axis, float& min, float& max)
	{
		min = vertices[0] * axis;
		max = min;

		for (int i = 1; i < vertices.size(); i++)
		{
			float proj = vertices[i] * axis;

			if (proj < min) min = proj;
			if (proj > max) max = proj;
		}
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

		Vector2f transformationA = collision.Manifold.Normal * collision.Manifold.Depth;
		collision.TransformA.position += transformationA;

		// B

		Vector2f transformationB = -collision.Manifold.Normal * collision.Manifold.Depth;
		collision.TransformB.position += transformationB;

		// Apply Impulse


	}
}