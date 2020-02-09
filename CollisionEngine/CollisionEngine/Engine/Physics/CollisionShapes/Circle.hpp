#ifndef PHYSICS_CIRCLE_HPP
#define PHYSICS_CIRCLE_HPP
#include "Shape.hpp"

namespace Physics { 

	class Circle : public Shape {
		friend class Collisions;

		float radius;

	public:

		Circle() : Shape(), radius(0.5f) { }
		
		/// getters

		virtual Bounds GetBounds(const Vector2& position) override;
		virtual ShapeType GetShapeType() const override;
		float GetRadius() { return radius; }


		/// setters

		void SetRadius(const float& radius_);

	};

}

#endif // !PHYSICS_CIRCLE_HPP