#ifndef PHYSICS_COLLISIONS2D_HPP
#define PHYSICS_COLLISIONS2D_HPP
#include "../Math/FloatVector.hpp"
#include "Bodies2D.hpp"

namespace Physics {
	using Math::float2;

	/// static class that check for and do collisions between bodies and colliders
	class Collisions2D {

		static float2 ClosestPointOnLine(float lx1, float ly1, float lx2, float ly2, float x0, float y0);
		static float2 CalculateBounceVelocity(const float2& velocity, const float2& surfaceNorm, const float& bounce);

	public:

		/// circle circle
		static void RigidCircle_RigidCircle(const float& delta, Rigidbody2D* bodyA, Circle2D* circleA, Rigidbody2D* bodyB, Circle2D* circleB);
		static void RigidCircle_StaticCircle(Rigidbody2D* bodyA, Circle2D* circleA, const Staticbody2D* bodyB, const Circle2D* circleB);

		/// circle line
		static void RigidCircle_StaticLine(Rigidbody2D* bodyA, Circle2D* circle, const Staticbody2D* bodyB, const Line2D* line);




	};
}

#endif // !PHYSICS_COLLISIONS2D_HPP