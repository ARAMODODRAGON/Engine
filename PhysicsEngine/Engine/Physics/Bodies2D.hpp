#ifndef PHYSICS_BODIES2D_HPP
#define PHYSICS_BODIES2D_HPP
#include "Shapes2D.hpp"

namespace Physics {

	class Rigidbody2D {
		friend class PhysicsScene2D;
		// should this body be updated
		bool simulated;

		// body position/rotation variables
		float2 position;
		float2 velocity;
		float2 acceleration;
		float rotation;
		float angularVelocity;
		float angularAcceleration;

		// body shape variables
		ShapeType2D shapeType;
		Shape2D* shape;

	public:

		Rigidbody2D();
		~Rigidbody2D();

		/// setters
		void SetSimulated(const bool& simulated_) { simulated = simulated_; }
		void SetPosition(const float2 position_) { position = position_; }
		void SetVelocity(const float2 velocity_) { velocity = velocity_; }
		void SetAcceleration(const float2 acceleration_) { acceleration = acceleration_; }
		void SetRotation(const float rotation_) { rotation = rotation_; }
		void SetAngularVelocity(const float angularVelocity_) { angularVelocity = angularVelocity_; }
		void SetAngularAcceleration(const float angularAcceleration_) { angularAcceleration = angularAcceleration_; }
		template<typename T>
		T* SetShape() {
			delete shape; // delete the old shape
			T* temp = new T(); // create a new shape of type T
			shape = temp; // store it in the shape pointer
			shapeType = shape->GetShapeType2D(); // get the type
			return temp; // return
		}

		/// getters
		bool GetSimulated() { return simulated; }
		float2 GetPosition() { return position; }
		float2 GetVelocity() { return velocity; }
		float2 GetAcceleration() { return acceleration; }
		float GetRotation() { return rotation; }
		float GetAngularVelocity() { return angularVelocity; }
		float GetAngularAcceleration() { return angularAcceleration; }
		template<typename T>
		T* GetShape() { return static_cast<T*>(shape); }

	};

	class Staticbody2D {
		friend class PhysicsScene2D;
		// should this body be updated
		bool simulated;

		// body position/rotation variables
		float2 position;
		float rotation;

		// body shape variables
		ShapeType2D shapeType;
		Shape2D* shape;

	public:

		Staticbody2D();
		~Staticbody2D();

		/// setters
		void SetSimulated(const bool& simulated_) { simulated = simulated_; }
		void SetPosition(const float2 position_) { position = position_; }
		void SetRotation(const float rotation_) { rotation = rotation_; }
		template<typename T>
		T* SetShape() {
			delete shape; // delete the old shape
			T* temp = new T(); // create a new shape of type T
			shape = temp; // store it in the shape pointer
			shapeType = shape->GetShapeType2D(); // get the type
			return temp; // return
		}

		/// getters
		bool GetSimulated() { return simulated; }
		float2 GetPosition() { return position; }
		float GetRotation() { return rotation; }
		template<typename T>
		T* GetShape() { return static_cast<T*>(shape); }
	};
}

#endif // !PHYSICS_BODIES2D_HPP