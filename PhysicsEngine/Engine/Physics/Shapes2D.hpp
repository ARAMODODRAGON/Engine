#ifndef PHYSICS_SHAPES2D_HPP
#define PHYSICS_SHAPES2D_HPP
#include "../Math/FloatVector.hpp"
#include "../Math/AABB.hpp"

namespace Physics {
	using Math::float2;
	using Math::AABB2D;

	enum class ShapeType2D : unsigned char { Circle, Line, Capsule, Box, AABox };

	struct Circle2D {
		float radius = 0.5f;
		Circle2D() { }
	};

	AABB2D Circle2D_CreateAABB2D(const Circle2D& sphere, const float2& position);

	struct Line2D {
		float2 start = float2(0.0f, 0.5f);
		float2 end = float2(0.0f, -0.5f);
		Line2D() { }
	};

	struct Capsule2D {
		float2 start = float2(0.0f, 0.5f);
		float2 end = float2(0.0f, -0.5f);
		float radius = 0.5f;
		Capsule2D() { }
	};

	struct Box2D {
		float2 top_left = float2(-0.5f, 0.5f);
		float2 top_right = float2(0.5f, 0.5f);
		float2 bottom_left = float2(-0.5f, -0.5f);
		float2 bottom_right = float2(0.5f, -0.5f);
		Box2D() { }
	};

	struct AABox2D {
		float2 min = float2(-0.5f, -0.5f);
		float2 max = float2(0.5f, 0.5f);
	};
}

#endif // !PHYSICS_SHAPES2D_HPP