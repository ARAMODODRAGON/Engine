#include "Bounds.h"

Bounds::Bounds()
	: min(ivec2(0)), max(ivec2(1)) { }

Bounds::Bounds(const vec2& min_, const vec2& max_)
	: min(min_), max(max_) { }

bool Bounds::Intersects(const Bounds& a, const Bounds& b) {
	return (a.min.x > b.min.x&& a.min.x < b.max.x) || (b.min.x > a.min.x&& b.min.x < a.max.x)
		&& (a.min.y > b.min.y&& a.min.y < b.max.y) || (b.min.y > a.min.y&& b.min.y < a.max.y);
}

bool Bounds::Contains(const Bounds& con, const Bounds& bo) {
	return con.min.x < bo.min.x && con.max.x > bo.max.x 
		&& con.min.y < bo.min.y && con.max.y > bo.max.y;
}
