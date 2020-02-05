#include "Body.h"
#include "Collider.h"
#include "PhysicsScene.h"
#include "Collider.h"

void Body::CollisionAlert() {
	// get the components list from the gameobject
	list<Component*>* components = GetGameObject()->GetComponentList();

	// call OnCollision if listening
	for (Component* comp : *components)
		if (comp->HasEventFlags(EventFlags::OnCollision))
			comp->OnCollision();
}

Body::Body()
	: Component()
	, bodyType(BodyType::Dynamic)
	, collider(nullptr)
	, velocity(vec2(0))
	, acceleration(vec2(0))
	, angularVelocity(0.0f)
	, angularAcceleration(0.0f) {
	// add *this* to physics scene
	PhysicsScene::GetSingleton()->AddBody(this);

}

Body::~Body() {
	if (collider) delete collider;
	collider = nullptr;

	// remove from the physics scene
	PhysicsScene::GetSingleton()->RemoveBody(this);
}

Bounds Body::GetNewBounds() {
	if (collider)
		return collider->GetNewBounds();
	return Bounds(vec2(0), vec2(0));
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
