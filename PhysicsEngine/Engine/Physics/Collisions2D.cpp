#include "Collisions2D.hpp"

namespace Physics {

	float2 Collisions2D::ClosestPointOnLine(float lx1, float ly1, float lx2, float ly2, float x0, float y0) {
		float A1 = ly2 - ly1;
		float B1 = lx1 - lx2;
		float C1 = (ly2 - ly1) * lx1 + (lx1 - lx2) * ly1;
		float C2 = -B1 * x0 + A1 * y0;
		float det = A1 * A1 - -B1 * B1;
		float cx = 0;
		float cy = 0;

		if (det != 0) {
			cx = ((A1 * C1 - B1 * C2) / det);
			cy = ((A1 * C2 - -B1 * C1) / det);
		} else {
			cx = x0;
			cy = y0;
		}

		if (lx1 < lx2 && cx < lx1) {
			cx = lx1;
			cy = ly1;
		} else if (lx2 < lx1 && cx < lx2) {
			cx = lx2;
			cy = ly2;
		} else if (ly1 < ly2 && cy < ly1) {
			cx = lx1;
			cy = ly1;
		} else if (ly2 < ly1 && cy < ly2) {
			cx = lx2;
			cy = ly2;
		}

		return float2(cx, cy);
	}

	float2 Collisions2D::CalculateBounceVelocity(
		const float2& velocity,
		const float2& surfaceNorm,
		const float& bounce
	) {
		return Math::Relfect(velocity, Math::Normalize(surfaceNorm) * bounce);
	}

	void Collisions2D::RigidCircle_RigidCircle(
		const float& delta,
		Rigidbody2D* bodyA,
		Circle2D* circleA,
		Rigidbody2D* bodyB,
		Circle2D* circleB
	) {
		// distance between the two bodies (points to A)
		float2 normal = bodyA->position - bodyB->position;
		float minDist = circleA->radius + circleB->radius;

		if (Math::SqrLength(normal) < minDist * minDist) {
			// points to A
			normal = Math::Normalize(normal) * (minDist - Math::Length(normal));

			// push
			bodyA->position += normal;
			bodyB->position -= normal;

			// bounce
			if (Math::Dot(bodyA->velocity, normal) < 0)
				bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, 0.8f);


			if (Math::Dot(bodyB->velocity, normal) > 0)
				bodyB->velocity = CalculateBounceVelocity(bodyB->velocity, -normal, 0.8f);

			//PRINT(TEXT(bodyA->velocity.x) + "," + TEXT(bodyA->velocity.y) + "||" + TEXT(bodyB->velocity.x) + "," + TEXT(bodyB->velocity.y));

		}
	}

	void Collisions2D::RigidCircle_StaticCircle(
		Rigidbody2D* bodyA,
		Circle2D* circleA,
		const Staticbody2D* bodyB,
		const Circle2D* circleB
	) {
		// distance between the two bodies (points to A)
		float2 normal = bodyA->position - bodyB->position;
		float minDist = circleA->radius + circleB->radius;

		if (Math::SqrLength(normal) < minDist * minDist) {
			// points to A
			normal = Math::Normalize(normal) * (minDist - Math::Length(normal));

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, 0.8f);

		}
	}

	void Collisions2D::RigidCircle_StaticLine(
		Rigidbody2D* bodyA,
		Circle2D* circle,
		const Staticbody2D* bodyB,
		const Line2D* line
	) {
		float2 point = ClosestPointOnLine(
			line->end.x + bodyB->position.x,
			line->end.y + bodyB->position.y,
			line->start.x + bodyB->position.x,
			line->start.y + bodyB->position.y,
			bodyA->position.x, bodyA->position.y
		);

		// distance between the two bodies (points to A)
		float2 normal = bodyA->position - point;

		if (Math::SqrLength(normal) < circle->radius * circle->radius) {
			// points to A
			normal = Math::Normalize(normal) * (circle->radius - Math::Length(normal));

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = CalculateBounceVelocity(bodyA->velocity, normal, 0.8f);

		}

	}

}