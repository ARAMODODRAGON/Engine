#ifndef MATH_AABB_HPP
#define MATH_AABB_HPP
#include "FloatVector.hpp"

namespace Math {

	struct AABB {
		float3 min, max;

		AABB() : min(0.0f), max(0.0f) { }
	};

	bool AABB_Intersects(const AABB& b0, const AABB& b1);

	struct AABB2D {
		float2 min, max;

		AABB2D() : min(0.0f), max(0.0f) { }
	};

	bool AABB2D_Intersects(const AABB2D& b0, const AABB2D& b1);

}

#endif // !MATH_AABB_HPP