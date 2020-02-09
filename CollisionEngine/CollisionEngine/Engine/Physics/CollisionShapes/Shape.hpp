#ifndef PHYSICS_SHAPE_HPP
#define PHYSICS_SHAPE_HPP
#include "../../Common.hpp"
#include "../Bounds.hpp"

namespace Physics {

	enum class ShapeType : ubyte { None, Circle, Line, Box, };

	class Body;

	class Shape {
		friend Body;
	protected:

		// a reference to the owning body
		Body* body;

	public:

		Shape() : body(nullptr) { }


		/// getters

		Body* GetBody() { return body; }
		virtual Bounds GetBounds(const Vector2& position) = 0;
		virtual ShapeType GetShapeType() const = 0;
	};
}

#endif // !PHYSICS_SHAPE_HPP