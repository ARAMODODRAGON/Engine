#include "Body.hpp"

namespace Physics {

	Body::Body() : shape(nullptr), type(BodyType::Dynamic) { }

	Body::~Body() { 
		if (shape) delete shape; shape = nullptr;
	}

	void Body::SetShape(Shape* shape_) {
		if (shape) delete shape;

		shape = shape_;
	}

}
