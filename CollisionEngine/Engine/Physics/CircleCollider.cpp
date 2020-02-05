#include "CircleCollider.h"
#include "Transform.h"

Bounds CircleCollider::GetNewBounds() {
	// this should only be called from the body so it assumes that *body* is not nullptr

	vec2 pos = body->GetTransform()->GetLocalPosition();

	return Bounds(vec2(pos.x - radius, pos.y - radius), vec2(pos.x + radius, pos.y + radius));

}

float CircleCollider::GetRadius() {
	return radius;
}

void CircleCollider::SetRadius(const float& radius_) { 
	radius = radius_;
}
