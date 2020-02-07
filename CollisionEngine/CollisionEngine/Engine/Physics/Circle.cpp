#include "Circle.hpp"

namespace Physics {

	Circle::Circle() : radius(0.5f) { }

	Bounds Circle::GetBounds(const Vector2& pos) {
		return Bounds(pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
	}

	ShapeType Circle::GetShapeType() {
		return ShapeType::Circle;
	}

}