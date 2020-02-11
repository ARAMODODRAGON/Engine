#ifndef PHYSICS_SHAPES2D_HPP
#define PHYSICS_SHAPES2D_HPP
#include "../common.hpp"
#include "../Math/FloatVector.hpp"
#include "../Math/AABB.hpp"

namespace Physics {
	using Math::float2;
	using Math::AABB2D;

	enum class ShapeType2D : ubyte { None, Circle, Line, Capsule, Box, AABox };

	struct Shape2D {
		virtual ShapeType2D GetShapeType2D() = 0;
	};

	struct Circle2D : public Shape2D {
		float radius;

		Circle2D(float radius_ = 0.5f)
			: radius(radius_) { }
		virtual ShapeType2D GetShapeType2D() override { return ShapeType2D::Circle; }
	};

	struct Line2D : public Shape2D {
		float2 start;
		float2 end;

		Line2D()
			: start(0.0f, -0.5f), end(0.0f, 0.5f) { }
		virtual ShapeType2D GetShapeType2D() override { return ShapeType2D::Line; }
	};

	struct Capsule2D : public Shape2D {
		float2 start;
		float2 end;
		float radius;

		Capsule2D(float radius_ = 0.5f)
			: start(0.0f, -0.5f), end(0.0f, 0.5f), radius(radius_) { }
		virtual ShapeType2D GetShapeType2D() override { return ShapeType2D::Capsule; }
	};

	struct Box2D : public Shape2D {
		float2 topLeft = float2(-0.5f, 0.5f);
		float2 topRight = float2(0.5f, 0.5f);
		float2 bottomLeft = float2(-0.5f, -0.5f);
		float2 bottomRight = float2(0.5f, -0.5f);

		Box2D()
			: topLeft(-0.5f, 0.5f)
			, topRight(0.5f, 0.5f)
			, bottomLeft(-0.5f, -0.5f)
			, bottomRight(0.5f, -0.5f) { }
		virtual ShapeType2D GetShapeType2D() override { return ShapeType2D::Box; }
	};

	struct AABox2D : public Shape2D {
		float2 min;
		float2 max;

		AABox2D() : min(-0.5f, -0.5f), max(0.5f, 0.5f) { }
		virtual ShapeType2D GetShapeType2D() override { return ShapeType2D::AABox; }
	};
}

#endif // !PHYSICS_SHAPES2D_HPP