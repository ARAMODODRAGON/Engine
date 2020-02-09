#ifndef PHYSICS_BOUNDS_HPP
#define PHYSICS_BOUNDS_HPP
#include "../Math/Vector2.hpp"
using Math::Vector2;

struct Bounds {

	Vector2 min;
	Vector2 max;


	Bounds()
		: min(Vector2::ZERO), max(Vector2::ZERO) { }
	Bounds(const float& minX, const float& minY, const float& maxX, const float& maxY)
		: min(minX, minY), max(maxX, maxY) { }
	Bounds(const Vector2& min, const Vector2& max) 
		: min(min), max(max) { }


	/// static functions

	static bool Intersects(const Bounds& b0, const Bounds& b1) {
		return (b0.min.x > b1.min.x&& b0.min.x < b1.max.x) || (b1.min.x > b0.min.x&& b1.min.x < b0.max.x)
			&& (b0.min.y > b1.min.y&& b0.min.y < b1.max.y) || (b1.min.y > b0.min.y&& b1.min.y < b0.max.y);
	}
	static bool Contains(const Bounds& container, const Bounds& bounds) {
		return container.min.x < bounds.min.x && container.max.x > bounds.max.x
			&& container.min.y < bounds.min.y && container.max.y > bounds.max.y;
	}

};

#endif // !PHYSICS_BOUNDS_HPP