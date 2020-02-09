#include "Collisions.hpp"
#include "../Core/Debug.hpp"
#include "../Math/Mathf.hpp"
using namespace Math;

namespace Physics {

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
			normal = Vector2::Normalized(normal) * (minDist - normal.Length());

			// push
			bodyA->position += normal;

			// bounce
			bodyA->velocity = Vector2::Reflect(bodyA->velocity, Vector2::Normalized(normal) * Mathf::Halfway(bodyA->bounce, 1.0f - bodyB->bounce));

		}
	}


}