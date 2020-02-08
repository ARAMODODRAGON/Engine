#include "Bounds.hpp"

Bounds::Bounds() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) { }

Bounds::Bounds(const float& minX, const float& minY, const float& maxX, const float& maxY)
	: x(minX), y(minY), w(maxX - minX), h(maxY - minY) { }

Bounds::Bounds(const Vector2& min, const Vector2& max)
	: x(min.x), y(min.y), w(max.x - min.x), h(max.y - min.y) { }

bool Bounds::Intersects(const Bounds& a, const Bounds& b) {
	return ((a.x <= b.x && (a.x + a.w) >= b.x) || (b.x <= a.x && (b.x + b.w) >= a.x))
		&& ((a.y <= b.y && (a.y + a.h) >= b.y) || (b.y <= a.y && (b.y + b.h) >= a.y));
}

bool Bounds::Contains(const Bounds& con, const Bounds& bo) {
	return false;
}
