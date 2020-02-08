#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP
#include "Body.hpp"
#include "Shape.hpp"
#include "Circle.hpp"

namespace Physics {

	/// static class that check for and do collisions between bodies and colliders
	struct Collisions {

		/// circle circle
		////static void Circle_DynamCircle(const float& delta, Body* bodyA, Circle* circleA, Body* bodyB, Circle* circleB);
		static void Circle_StaticCircle(Body* bodyA, Circle* circleA, const Body* bodyB, const Circle* circleB);
		/// circle line
		////static void Circle_DynamLine();
		////static void Circle_StaticLine(); // next
		/// circle box
		////static void Circle_DynamBox();
		////static void Circle_StaticBox();

		/// line circle
		////static void Line_DynamCircle();
		////static void Line_StaticCircle();
		/// line line
		////static void Line_DynamLine();
		////static void Line_StaticLine();
		/// line box
		////static void Line_DynamBox();
		////static void Line_StaticBox();

		/// box circle
		////static void Box_DynamCircle();
		////static void Box_StaticCircle();
		/// box line
		////static void Box_DynamLine();
		////static void Box_StaticLine();
		/// box box
		////static void Box_DynamBox();
		////static void Box_StaticBox();


	};
}

#endif // !COLLISIONS_HPP