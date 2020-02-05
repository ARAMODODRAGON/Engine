#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H
#include "Collider.h"


class CircleCollider : public Collider {
	// body and collider are friends
	friend class Body;

	// size of the collider
	float radius;

	// get the bounds
	virtual Bounds GetNewBounds();

public:

	CircleCollider();

	/// getters
	float GetRadius();

	/// setters
	void SetRadius(const float& radius);

};


#endif // !CIRCLE_COLLIDER_H