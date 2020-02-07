#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP
#include "Body.hpp"
#include "Shape.hpp"
#include "Circle.hpp"

namespace Physics {

	/// static class that check for and do collisions between bodies and colliders
	struct Collisions {

		static void Circle_DynamCircle(const float& delta, Body* bodyA, Circle* circleA, Body* bodyB, Circle* circleB);
		static void Circle_StaticCircle(const float& delta, Body* bodyA, Circle* circleA, const Body* bodyB, const Circle* circleB);

	};
}

#endif // !COLLISIONS_HPP