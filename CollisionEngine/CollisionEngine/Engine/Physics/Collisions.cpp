#include "Collisions.hpp"
#include "../Core/Debug.hpp"
#include "../Math/Mathf.hpp"
using namespace Math;

namespace Physics {


	Vector2 Collisions::ClosestPointOnLine(float lx1, float ly1, float lx2, float ly2, float x0, float y0) {
		float A1 = ly2 - ly1;
		float B1 = lx1 - lx2;
		float C1 = (ly2 - ly1) * lx1 + (lx1 - lx2) * ly1;
		float C2 = -B1 * x0 + A1 * y0;
		float det = A1 * A1 - -B1 * B1;
		float cx = 0;
		float cy = 0;

		if (det != 0) {
			cx = (float)((A1 * C1 - B1 * C2) / det);
			cy = (float)((A1 * C2 - -B1 * C1) / det);
		} else {
			cx = x0;
			cy = y0;
		}

		if (cx < lx1 && cx < lx2 && cy < ly1 && cy < ly2) {
			cx = (lx1 < lx2 ? lx1 : lx2);
			cy = (ly1 < ly2 ? ly1 : ly2);
		} else if (cx > lx1 && cx > lx2 && cy > ly1 && cy > ly2) {
			cx = (lx1 > lx2 ? lx1 : lx2);
			cy = (ly1 > ly2 ? ly1 : ly2);
		}

		return Vector2(cx, cy);
	}

	Vector2 Collisions::CalculateBounceVelocity(
		const Vector2& velocity, 
		const Vector2& surfaceNorm, 
		const float& bounceA, 
		const float& bounceB
	) {
		return Vector2::Reflect(velocity, Vector2::Normalized(surfaceNorm) * Mathf::Halfway(bounceA, 1.0f - bounceB));
	}


	void Collisions::RigidCircle_StaticCircle(
		Rigidbody* bodyA,
		Circle* shapeA,
		const Staticbody* bodyB,
		const Circle* shapeB
	) {
		// distance between the two bodies (points to A)
		Vector2 normal = bodyA->position - bodyB->position;
		float minDist = shapeA->radius + shapeB->radius;

		if (normal.SqrLength() < minDist * minDist) {
			// points to A
			normal = Vector2::Normalized(normal) * (minDist - normal.Length());

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, bodyA->bounce, bodyB->bounce);

		}
	}

	void Collisions::RigidCircle_StaticLine(
		Rigidbody* bodyA,
		Circle* shapeA,
		const Staticbody* bodyB,
		const Line* shapeB
	) {
		Vector2 point = ClosestPointOnLine(
			shapeB->end.x + bodyB->position.x,
			shapeB->end.y + bodyB->position.y,
			shapeB->start.x + bodyB->position.x,
			shapeB->start.y + bodyB->position.y,
			bodyA->position.x, bodyA->position.y
		);

		// distance between the two bodies (points to A)
		Vector2 normal = bodyA->position - point;

		if (normal.SqrLength() < shapeA->radius * shapeA->radius) {
			// points to A
			normal = Vector2::Normalized(normal) * (shapeA->radius - normal.Length());

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, bodyA->bounce, bodyB->bounce);
			//bodyA->velocity = Vector2::Reflect(bodyA->velocity, Vector2::Normalized(normal) * Mathf::Halfway(bodyA->bounce, 1.0f - bodyB->bounce));

		}

	}
}