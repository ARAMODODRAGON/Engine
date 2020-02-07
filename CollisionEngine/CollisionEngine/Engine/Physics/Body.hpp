#ifndef BODY_HPP
#define BODY_HPP
#include "../Common.hpp"
#include "../Math/Vector2.hpp"
#include "Shape.hpp"

namespace Physics {

	enum class BodyType : ubyte {
		Dynamic,
		Static,
	};

	class Body {

		friend class PhysicsScene;

		Shape* shape;
		BodyType type;

	public:

		Vector2 position;
		Vector2 velocity;
		Vector2 acceleration;

		//float rotation;
		//float angualarVelocity;
		//float angualarAcceleration;

		Body();
		~Body();

		/// setters

		void SetShape(Shape* shape);
		void SetBodyType(BodyType type_) { type = type_; }

		/// getters

		BodyType GetBodyType() { return type; }
		Shape* GetShape() { return shape; }
		Bounds GetBounds() { return shape->GetBounds(position); }

	};
}

#endif // !BODY_HPP