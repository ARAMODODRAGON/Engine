#ifndef COLLIDER_H
#define COLLIDER_H
#include "../Common.h"
#include "../Math/Bounds.h"
#include "Body.h"

class Collider {
protected:
	// body and collider are friends
	friend class Body;

	// the connected body
	Body* body;

	/// getter
	// this should only be called from body to get and updated bounds
	virtual Bounds GetNewBounds() = 0;

public:

	Collider() : body(nullptr) { }

	// getters
	Body* GetBody();

	// setters

};

#endif // !COLLIDER_H