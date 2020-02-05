#include "PhysicsScene.h"
#include "../Debug.h"
#include "Body.h"
#include "Transform.h"

PhysicsScene* PhysicsScene::singleton = nullptr;
PhysicsScene* PhysicsScene::GetSingleton() {
	return singleton;
}

PhysicsScene::PhysicsScene(const uint& substeps_)
	: substeps(substeps_), physList(PhysList()) {
	// set the singleton
	if (singleton) Debug::PrintError("there are multiple physics scenes");
	else singleton = this;
}

PhysicsScene::~PhysicsScene() {
	// delete the singleton
	if (singleton == this) singleton = false;
}

void PhysicsScene::DoStep(const float& delta) {
	// call substep the set number of times
	for (ubyte i = 0; i < substeps; i++) {
		// call substep with the set delta value
		DoSubstep(delta / substeps);
	}
}

void PhysicsScene::AddBody(Body* body) {
	BNode* node = new BNode();
	node->body = body;
	node->bounds = body->GetNewBounds();
	physList.push_back(node);
}

void PhysicsScene::RemoveBody(Body* body) {
	// find the body and remove it
	physList.remove_if([body](BNode* node)->bool {
		return node->body == body;
	});
}

void PhysicsScene::DoSubstep(const float& delta) {
	for (BNode* node : physList) {
		// first move the body
		SubstepPhysics(node->bounds, node->body, delta);

		// then check collisions against every other body
		SubstepCollisions(node);
	}
}

void PhysicsScene::SubstepPhysics(Bounds& bounds, Body* body, const float& delta) {
	// dynamic bodies have full physics
	// kinematic bodies dont move but still update their bounds
	// static bodies should never move and so they should never update thier bounds or physics

	if (body->bodyType == BodyType::Dynamic) {
		// calculate linear velocity and position
		body->velocity += body->acceleration * delta;
		body->GetTransform()->position += body->velocity * delta;
		// calculate angular velociy and rotation
		body->angularVelocity += body->angularAcceleration * delta;
		body->GetTransform()->rotation += body->angularVelocity * delta;
		// update the bounds
		bounds = body->GetNewBounds();
	}
	if (body->bodyType == BodyType::Kinematic) {
		// update the bounds
		bounds = body->GetNewBounds();
	}
}

void PhysicsScene::SubstepCollisions(BNode* node) {
	for (BNode* other : physList) {
		// skip itself
		if (node->body == other->body) continue;

		// check if the bounds overlap, if so do collisions
		if (Bounds::Intersects(node->bounds, other->bounds)) {
			// overlaps, now check and do collisions
			CheckCollisions(node->body, other->body);
		}

	}
}

void PhysicsScene::CheckCollisions(Body* bodyA, Body* bodyB) {

	Debug::Print("the bodies have intersected!");

	bodyA->CollisionAlert();
	bodyB->CollisionAlert();

}
