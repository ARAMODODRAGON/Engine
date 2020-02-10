#include "Line.hpp"
#include "../Bodies/Body.hpp"

namespace Physics {

	Bounds Line::GetBounds(const Vector2& pos) {
		Bounds bounds;
		bounds.min.x = (start.x < end.x ? start.x : end.x) + pos.x;
		bounds.min.y = (start.y < end.y ? start.y : end.y) + pos.y;
		bounds.max.x = (start.x > end.x ? start.x : end.x) + pos.x;
		bounds.max.y = (start.y > end.y ? start.y : end.y) + pos.y;
		return bounds;
	}

	void Line::SetStart(const Vector2& start_) { 
		start = start_; body->UpdateBounds();
	}

	void Line::SetEnd(const Vector2& end_) { 
		end = end_; body->UpdateBounds();
	}

}
