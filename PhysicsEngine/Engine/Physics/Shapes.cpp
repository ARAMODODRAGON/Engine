#include "Shapes.hpp"

namespace Physics {

	AABB Sphere_CreateAABB(const Sphere& sphere, const float3& position) {
		AABB box;
		box.min = position - float3(sphere.radius);
		box.max = position + float3(sphere.radius);
		return box;
	}

}