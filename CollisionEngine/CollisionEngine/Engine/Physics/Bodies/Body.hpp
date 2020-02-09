#ifndef PHYSICS_BODY_HPP
#define PHYSICS_BODY_HPP
#include "../../Common.hpp"
#include "../../Math/Vector2.hpp"
using Math::Vector2;
#include "../../Math/FMath.hpp"
using Math::FMath;
#include "../CollisionShapes/Shape.hpp"

namespace Physics {

	/// abstract class
	// base body class that is inherited by Rigidbody, KinematicBody, StaticBody
	class Body {
		friend class Collisions;
		friend class PhysicsScene;

	protected:
		/// should this body be simulated
		bool simulated;

		/// the collision shape and bounds
		Shape* shape;
		Bounds bounds;

		/// the position
		Vector2 position;

		/// material variables
		float bounce;


		Body() : simulated(true), shape(nullptr), position(Vector2::ZERO), bounce(0.3f) { }

	public:

		virtual ~Body() { shape->body = nullptr; }


		/// functions

		void UpdateBounds() {
			if (shape) bounds = shape->GetBounds(position);
			//else bounds = Bounds();
		}


		/// setters

		// sets the current shape and dereferneces the old shape
		void SetShape(Shape* shape_) {
			// the old shape should no longer reference this
			if (shape) shape->body = nullptr;
			// attach new shape
			shape = shape_;
			if (shape) {
				// detaches shape from other body
				if (shape->body) shape->body->SetShape(nullptr);
				// attach to this body
				shape->body = this;
			}
			// update bounds
			UpdateBounds();
		}
		void SetSimulated(const bool& simulated_) { simulated = simulated_; }
		void SetPosition(const Vector2& position_) { position = position_; UpdateBounds(); }
		// sets the bounciness of the rigidbody
		// @param bounce: ranges from 0.0f to 1.0f
		void SetBounce(const float& bounce_) { 
			bounce = FMath::Clamp(bounce_, 0.0f, 1.0f);
		}


		/// getters

		bool GetSimulated() { return simulated; }
		Shape* GetShape() { return shape; }
		Bounds GetBounds() { return bounds; }
		Vector2 GetPosition() { return position; }
		float GetBounce() { return bounce; }

	};
}

#endif // !PHYSICS_BODY_HPP