#ifndef PHYSICS_LINE_HPP
#define PHYSICS_LINE_HPP
#include "Shape.hpp"

namespace Physics {

	class Line : public Shape {
		friend class Collisions;

		Vector2 pointA, pointB;

	public:

		Line() : Shape(), pointA(Vector2::ZERO), pointB(Vector2::ZERO) { }


		// getters

		virtual Bounds GetBounds(const Vector2& position) override;
		virtual ShapeType GetShapeType() const override { return ShapeType::Line; }

	};

}

#endif // !LINE_HPP