#include "Collisions.hpp"
#include "../Core/Debug.hpp"
#include "../Math/FMath.hpp"
#include "../Math/VMath.hpp"
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

		if (lx1 < lx2 && cx < lx1) {
			cx = lx1; 
			cy = ly1;
		} else if (lx2 < lx1 && cx < lx2) {
			cx = lx2;
			cy - ly2;
		} else if (ly1 < ly2 && cy < ly1) {
			cx = lx1; 
			cy = ly1;
		} else if (ly2 < ly1 && cy < ly2) {
			cx = lx2;
			cy - ly2;
		}

		return Vector2(cx, cy);
	}

	Vector2 Collisions::CalculateBounceVelocity(
		const Vector2& velocity,
		const Vector2& surfaceNorm,
		const float& bounceA
	) {
		return VMath::Reflect(velocity, VMath::Normalized(surfaceNorm) * bounceA);
	}


	void Collisions::RigidCircle_RigidCircle(
		const float& delta, 
		Rigidbody* bodyA, 
		Circle* circleA, 
		Rigidbody* bodyB, 
		Circle* circleB
	) { 
		// distance between the two bodies (points to A)
		Vector2 normal = bodyA->position - bodyB->position;
		float minDist = circleA->radius + circleB->radius;

		if (normal.SqrLength() < minDist * minDist) {
			// points to A
			normal = VMath::Normalized(normal) * (minDist - normal.Length());

			// push
			bodyA->position += normal;
			bodyB->position -= normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, bodyA->bounce);
			bodyB->velocity = CalculateBounceVelocity(bodyB->velocity, -normal, bodyB->bounce);

			
			// update bounds
			bodyA->UpdateBounds();
			bodyB->UpdateBounds();


		}
	}

	void Collisions::RigidCircle_StaticCircle(
		Rigidbody* bodyA,
		Circle* circleA,
		const Staticbody* bodyB,
		const Circle* circleB
	) {
		// distance between the two bodies (points to A)
		Vector2 normal = bodyA->position - bodyB->position;
		float minDist = circleA->radius + circleB->radius;

		if (normal.SqrLength() < minDist * minDist) {
			// points to A
			normal = VMath::Normalized(normal) * (minDist - normal.Length());

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, bodyA->bounce);

			// update bounds and wake up
			bodyA->UpdateBounds();

		}
	}

	void Collisions::RigidCircle_StaticLine(
		Rigidbody* bodyA,
		Circle* circle,
		const Staticbody* bodyB,
		const Line* line
	) {
		Vector2 point = ClosestPointOnLine(
			line->end.x + bodyB->position.x,
			line->end.y + bodyB->position.y,
			line->start.x + bodyB->position.x,
			line->start.y + bodyB->position.y,
			bodyA->position.x, bodyA->position.y
		);

		// distance between the two bodies (points to A)
		Vector2 normal = bodyA->position - point;

		if (normal.SqrLength() < circle->radius * circle->radius) {
			// points to A
			normal = VMath::Normalized(normal) * (circle->radius - normal.Length());

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, bodyA->bounce);

			// update bounds
			bodyA->UpdateBounds();

		}

	}
}