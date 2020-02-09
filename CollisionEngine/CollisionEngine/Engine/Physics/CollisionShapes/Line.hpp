#ifndef PHYSICS_LINE_HPP
#define PHYSICS_LINE_HPP
#include "Shape.hpp"

namespace Physics {

	class Line : public Shape {
		friend class Collisions;

		Vector2 start, end;

	public:

		Line() : Shape(), start(Vector2::ZERO), end(Vector2::ZERO) { }


		/// getters

		virtual Bounds GetBounds(const Vector2& position) override;
		virtual ShapeType GetShapeType() const override { return ShapeType::Line; }
		Vector2 GetStart() { return start; }
		Vector2 GetEnd() { return end; }


		/// setters

		void SetStart(const Vector2& start_);
		void SetEnd(const Vector2& end_);

	};

}

#endif // !LINE_HPP