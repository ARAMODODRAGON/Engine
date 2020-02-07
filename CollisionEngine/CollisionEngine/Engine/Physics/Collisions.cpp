#include "Collisions.hpp"
#include <math.h>

namespace Physics {

	void Collisions::Circle_DynamCircle(
		const float& delta,
		Body* bodyA, 
		Circle* circleA,
		Body* bodyB,
		Circle* circleB
	) {
		// distance between bodies (points to A)
		Vector2 distance = bodyA->position - bodyB->position;
		// the min distance for the circles to overlap
		float minDistSqr = (circleA->radius * circleA->radius + circleB->radius * circleB->radius);

		// the circles are overlapping
		if (distance.SqrLength() < minDistSqr) {

			// calculate push
			// the direction from B to A multiplied by the overlapping distance
			Vector2 push = distance.Normalized() * sqrtf(minDistSqr - distance.SqrLength());

			// push bodyA and apply to velocity
			bodyA->position += push;
			bodyA->velocity += push;

			// reverse and apply to bodyB
			push = -push;
			bodyB->position += push;
			bodyB->velocity += push;
		}
	}

	void Collisions::Circle_StaticCircle(
		const float& delta,
		Body* bodyA,
		Circle* circleA,
		const Body* bodyB,
		const Circle* circleB
	) {
		// distance between bodies (points to A)
		Vector2 distance = bodyA->position - bodyB->position;
		// the min distance for the circles to overlap
		float minDistSqr = (circleA->radius * circleA->radius + circleB->radius * circleB->radius);

		// the circles are overlapping
		if (distance.SqrLength() < minDistSqr) {

			// calculate push
			// the direction from B to A multiplied by the overlapping distance
			Vector2 push = distance.Normalized() * sqrtf(minDistSqr - distance.SqrLength());

			// push bodyA and apply to velocity
			bodyA->position += push;
			bodyA->velocity += push;

		}
	}

}