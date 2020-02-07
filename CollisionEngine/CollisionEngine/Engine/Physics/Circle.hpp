#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Shape.hpp"

namespace Physics { 

	struct Circle : public Shape {

		float radius;

		Circle();
		
		virtual Bounds GetBounds(const Vector2& position) override;
		virtual ShapeType GetShapeType() override;
	};

}

#endif // !CIRCLE_HPP