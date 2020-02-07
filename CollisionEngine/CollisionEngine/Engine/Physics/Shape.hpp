#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "../Common.hpp"
#include "Bounds.hpp"

namespace Physics { 

	enum class ShapeType : ubyte {
		None,
		Box,
		Circle,
		Line,

	};

	struct Shape {
		virtual Bounds GetBounds(const Vector2& position) = 0;
		virtual ShapeType GetShapeType() = 0;
	};
}

#endif // !SHAPE_HPP