#include "Bodies2D.hpp"

namespace Physics {

	Body::Body()
		:simulated(true)
		, position(0.0f)
		, rotation(0.0f) { }

	Rigidbody2D::Rigidbody2D()
		: velocity(0.0f)
		, acceleration(0.0f)
		, angularVelocity(0.0f)
		, angularAcceleration(0.0f)
		, shapeType(ShapeType2D::None)
		, shape(nullptr) { }

	Rigidbody2D::~Rigidbody2D() {
		if (shape) delete shape;
		shape = nullptr;
	}

	Staticbody2D::Staticbody2D()
		: shapeType(ShapeType2D::None)
		, shape(nullptr) { }

	Staticbody2D::~Staticbody2D() {
		if (shape) delete shape;
		shape = nullptr;
	}


}