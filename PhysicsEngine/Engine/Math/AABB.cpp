#include "AABB.hpp"

namespace Math {

	bool AABB_Intersects(const AABB& b0, const AABB& b1) {
		return !(
			b0.min.x > b1.max.x ||
			b0.max.x < b1.min.x ||
			b0.min.y > b1.max.y ||
			b0.max.y < b1.min.y ||
			b0.min.z > b1.max.z ||
			b0.max.z < b1.min.z);
	}

	bool AABB2D_Intersects(const AABB2D& b0, const AABB2D& b1) {
		return !(
			b0.min.x > b1.max.x ||
			b0.max.x < b1.min.x ||
			b0.min.y > b1.max.y ||
			b0.max.y < b1.min.y);
	}

}