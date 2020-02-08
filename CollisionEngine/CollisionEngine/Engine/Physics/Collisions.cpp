#include "Collisions.hpp"
#include <math.h>
#include "../Core/Debug.hpp"

namespace Physics {

	void Collisions::Circle_StaticCircle(Body* bodyA,
		Circle* circleA,
		const Body* bodyB,
		const Circle* circleB
	) {
		// distance between the two bodies (points to A)
		Vector2 distance = bodyA->position - bodyB->position;
		float minDist = circleA->radius + circleB->radius;

		if (distance.SqrLength() < minDist * minDist) {
			// points to A
			Vector2 pushDir = distance.Normalized();
			float pushDist = minDist - distance.Length();

			// push A
			bodyA->position += pushDir * pushDist;
			bodyA->velocity += pushDir * pushDist;


		}
	}


}