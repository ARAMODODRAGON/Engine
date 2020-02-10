#ifndef PHYSICS_RIGIDBODY_HPP
#define PHYSICS_RIGIDBODY_HPP
#include "Body.hpp"

namespace Physics {

	enum class SleepMode : ubyte {
		Sleep,
		Awake,
	};

	class Rigidbody : public Body {
		friend class Collisions;
		friend class PhysicsScene;

		Vector2 velocity;
		Vector2 acceleration;

		SleepMode sleepMode;
		float waitDelta;

		Rigidbody() : Body(), velocity(Vector2::ZERO), acceleration(Vector2::ZERO), sleepMode(SleepMode::Awake), waitDelta(0.0f) { }

	public:

		virtual ~Rigidbody() override { }


		/// functions

		void WakeUp() { sleepMode = SleepMode::Awake; waitDelta = 0.0f; }
		void Sleep() { sleepMode = SleepMode::Sleep; waitDelta = 0.0f; }

		/// setters

		void SetVelocity(const Vector2& velocity_) { velocity = velocity_; WakeUp(); }
		void SetAcceleration(const Vector2& acceleration_) { acceleration = acceleration_; WakeUp(); }


		/// getters

		Vector2 GetVelocity() { return velocity; }
		Vector2 GetAcceleration() { return acceleration; }
		SleepMode GetSleepMode() { return sleepMode; }

	};

}

#endif // !PHYSICS_RIGIDBODY_HPP