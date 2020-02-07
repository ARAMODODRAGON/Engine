#ifndef BOUNDS_HPP
#define BOUNDS_HPP
#include "../Math/Vector2.hpp"

struct Bounds {

	float minX, minY;
	float maxX, maxY;

	Bounds();
	Bounds(const float& minX, const float& minY, const float& maxX, const float& maxY);
	Bounds(const Vector2& min, const Vector2& max);

	static bool Intersects(const Bounds& a, const Bounds& b);
	static bool Contains(const Bounds& container, const Bounds& bounds);
};

#endif // !BOUNDS_HPP