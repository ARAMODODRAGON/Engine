#include "Body.h"
#include "Collider.h"

Body::Body()
	: bodyType(BodyType::Dynamic), collider(nullptr) {

	// TODO: add *this* to physics scene

}

Body::~Body() {
	if (collider) delete collider;
	collider = nullptr;

	// TODO: remove *this* from physics scene
}

void Body::SetCollider(Collider* coll) {
	// first remove the current collider
	if (collider) {
		collider->body = nullptr;
		delete collider;
	}

	// set the new collider
	if (coll) coll->body = this; // check incase nullptr was passed
	collider = coll;

}

void Body::SetTransform(Transform* transform_) { 
	// set the transform
	transform = transform_;

	// TODO: if its nullptr remove from physics scene
}

void Body::SetBodyType(const BodyType& type_) { 
	// set the type
	bodyType = type_;
	
	// TODO: update the settings in the physics scene

}
