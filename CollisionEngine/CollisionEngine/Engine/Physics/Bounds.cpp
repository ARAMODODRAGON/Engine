#include "Bounds.hpp"

Bounds::Bounds()
	: minX(0.0f), minY(0.0f), maxX(1.0f), maxY(1.0f) { }

Bounds::Bounds(const float& minX_, const float& minY_, const float& maxX_, const float& maxY_) 
	: minX(minX_), minY(minY_), maxX(maxX_), maxY(maxY_) { }

Bounds::Bounds(const Vector2& min, const Vector2& max)
	: minX(min.x), minY(min.y), maxX(max.x), maxY(max.y) { }

bool Bounds::Intersects(const Bounds& a, const Bounds& b) {
	return (a.minX > b.minX && a.minX < b.maxX) || (b.minX > a.minX && b.minX < a.maxX)
		&& (a.minY > b.minY && a.minY < b.maxY) || (b.minY > a.minY && b.minY < a.maxY);
}

bool Bounds::Contains(const Bounds& con, const Bounds& bo) {
	return con.minX < bo.minX && con.maxX > bo.maxX
		&& con.minY < bo.minY && con.maxY > bo.maxY;
}
