#ifndef BOUNDS_H
#define BOUNDS_H

#include "../Common.h"

struct Bounds {

	vec2 min;
	vec2 max;

	Bounds();
	Bounds(const vec2& min, const vec2& max);

	static bool Intersects(const Bounds& a, const Bounds& b);
	static bool Contains(const Bounds& container, const Bounds& bounds);
};

#endif // !BOUNDS_H