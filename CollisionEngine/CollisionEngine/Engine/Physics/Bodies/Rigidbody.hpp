#ifndef PHYSICS_RIGIDBODY_HPP
#define PHYSICS_RIGIDBODY_HPP
#include "Body.hpp"

namespace Physics {

	class Rigidbody : public Body {
		friend class Collisions;
		friend class PhysicsScene;

		Vector2 velocity;
		Vector2 acceleration;

		Rigidbody() : Body(), velocity(Vector2::ZERO), acceleration(Vector2::ZERO) { }

	public:

		virtual ~Rigidbody() override { }


		/// setters

		void SetVelocity(const Vector2& velocity_) { velocity = velocity_; }
		void SetAcceleration(const Vector2& acceleration_) { acceleration = acceleration_; }


		/// getters

		Vector2 GetVelocity() { return velocity; }
		Vector2 GetAcceleration() { return acceleration; }

	};

}

#endif // !PHYSICS_RIGIDBODY_HPP