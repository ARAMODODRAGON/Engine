#include "Circle.hpp"
#include "../Bodies/Body.hpp"

namespace Physics {

	Bounds Circle::GetBounds(const Vector2& pos) {
		return Bounds(pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);
	}

	ShapeType Circle::GetShapeType() const {
		return ShapeType::Circle;
	}

	void Circle::SetRadius(const float& radius_) {
		radius = radius_;
		if (body) body->UpdateBounds();
	}

}