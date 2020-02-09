#ifndef PHYSICS_COLLISIONS_HPP
#define PHYSICS_COLLISIONS_HPP
#include "Bodies/Rigidbody.hpp"
#include "Bodies/Staticbody.hpp"
#include "CollisionShapes/Shape.hpp"
#include "CollisionShapes/Circle.hpp"

namespace Physics {

	/// static class that check for and do collisions between bodies and colliders
	class Collisions {
	public:

		/// circle circle
		////static void RigidCircle_RigidCircle(const float& delta, Body* bodyA, Circle* circleA, Body* bodyB, Circle* circleB);
		static void RigidCircle_StaticCircle(Rigidbody* bodyA, Circle* circleA, const Staticbody* bodyB, const Circle* circleB);
		/// circle line
		////static void RigidCircle_RigidLine();
		////static void RigidCircle_StaticLine(); // next
		/// circle box
		////static void RigidCircle_RigidBox();
		////static void RigidCircle_StaticBox();

		/// line circle
		////static void RigidLine_RigidCircle();
		////static void RigidLine_StaticCircle();
		/// line line
		////static void RigidLine_RigidLine();
		////static void RigidLine_StaticLine();
		/// line box
		////static void RigidLine_RigidBox();
		////static void RigidLine_StaticBox();

		/// box circle
		////static void RigidBox_RigidCircle();
		////static void RigidBox_StaticCircle();
		/// box line
		////static void RigidBox_RigidLine();
		////static void RigidBox_StaticLine();
		/// box box
		////static void RigidBox_RigidBox();
		////static void RigidBox_StaticBox();


	};
}

#endif // !PHYSICS_COLLISIONS_HPP