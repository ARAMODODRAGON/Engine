#ifndef PHYSICS_BODIES2D_HPP
#define PHYSICS_BODIES2D_HPP
#include "Shapes2D.hpp"

namespace Physics {

	class Body {
	protected:
		// should this body be updated
		bool simulated;

		float2 position;
		float rotation;

	public:

		Body();
		
		/// setters
		void SetSimulated(const bool& simulated_) { simulated = simulated_; }
		void SetPosition(const float2 position_) { position = position_; }
		void SetRotation(const float rotation_) { rotation = rotation_; }

		/// getters
		bool GetSimulated() { return simulated; }
		float2 GetPosition() { return position; }
		float GetRotation() { return rotation; }

	};

	class Rigidbody2D : public Body {
		friend class PhysicsScene2D;
		friend class Collisions2D;

		// body position/rotation variables
		float2 velocity;
		float2 acceleration;
		float angularVelocity;
		float angularAcceleration;

		// body shape variables
		ShapeType2D shapeType;
		Shape2D* shape;

	public:

		Rigidbody2D();
		~Rigidbody2D();

		/// setters
		void SetVelocity(const float2 velocity_) { velocity = velocity_; }
		void SetAcceleration(const float2 acceleration_) { acceleration = acceleration_; }
		void SetAngularVelocity(const float angularVelocity_) { angularVelocity = angularVelocity_; }
		void SetAngularAcceleration(const float angularAcceleration_) { angularAcceleration = angularAcceleration_; }
		template<typename T>
		T* SetShape() {
			delete shape; // delete the old shape
			T* temp = new T(); // create a new shape of type T
			shape = temp; // store it in the shape pointer
			shapeType = shape->GetShapeType2D(); // get the type
			shape->body = this; // set the body reference
			return temp; // return
		}

		/// getters
		float2 GetVelocity() { return velocity; }
		float2 GetAcceleration() { return acceleration; }
		float GetAngularVelocity() { return angularVelocity; }
		float GetAngularAcceleration() { return angularAcceleration; }
		template<typename T>
		T* GetShape() { return static_cast<T*>(shape); }

	};

	class Staticbody2D : public Body {
		friend class PhysicsScene2D;
		friend class Collisions2D;

		// body shape variables
		ShapeType2D shapeType;
		Shape2D* shape;

	public:

		Staticbody2D();
		~Staticbody2D();

		template<typename T>
		T* SetShape() {
			delete shape; // delete the old shape
			T* temp = new T(); // create a new shape of type T
			shape = temp; // store it in the shape pointer
			shapeType = shape->GetShapeType2D(); // get the type
			shape->body = this; // set the body reference
			return temp; // return
		}

		/// getters
		template<typename T>
		T* GetShape() { return static_cast<T*>(shape); }
	};
}

#endif // !PHYSICS_BODIES2D_HPP