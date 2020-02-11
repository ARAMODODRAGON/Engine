#ifndef PHYSICS_SHAPES_HPP
#define PHYSICS_SHAPES_HPP
#include "../Math/FloatVector.hpp"
#include "../Math/AABB.hpp"

namespace Physics {
	using Math::float3;
	using Math::AABB;

	enum class ShapeType : unsigned char { Sphere, Line, Capsule, Plane, Box };

	struct Sphere {
		float radius = 0.5f;
		Sphere() { }
	};

	AABB Sphere_CreateAABB(const Sphere& sphere, const float3& position);

	struct Line {
		float3 start = float3(0.0f, 0.5f, 0.0f);
		float3 end = float3(0.0f, -0.5f, 0.0f);
		Line() { }
	};

	struct Capsule {
		float3 start = float3(0.0f, 0.5f, 0.0f);
		float3 end = float3(0.0f, -0.5f, 0.0f);
		float radius = 0.5f;
		Capsule() { }
	};

	struct Plane {
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;
		Plane() { }
	};

	struct Box {
		Plane p0;
		Plane p1;
		Plane p2;
		Plane p3;
		Plane p4;
		Plane p5;
		Box() { }
	};


}

#endif // !PHYSICS_SHAPES_HPP