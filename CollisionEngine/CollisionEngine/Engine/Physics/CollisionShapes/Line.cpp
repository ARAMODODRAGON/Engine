#include "Line.hpp"

namespace Physics {

	Bounds Line::GetBounds(const Vector2& pos) {
		Bounds bounds;
		bounds.min.x = (pointA.x < pointB.x ? pointA.x : pointB.x);
		bounds.min.y = (pointA.y < pointB.y ? pointA.y : pointB.y);
		bounds.max.x = (pointA.x > pointB.x ? pointA.x : pointB.x);
		bounds.max.y = (pointA.y > pointB.y ? pointA.y : pointB.y);
		return bounds;
	}

}
