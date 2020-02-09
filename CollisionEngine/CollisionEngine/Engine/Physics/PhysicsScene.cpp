#include "PhysicsScene.hpp"
#include "../Core/Debug.hpp"
#include "Collisions.hpp"

namespace Physics {

	PhysicsScene::PhysicsScene(uint substeps_, float timestep_) : substeps(0), timestep(0.0f) {
		SetSubsteps(substeps_);
		SetTimestep(timestep_);
	}

	PhysicsScene::~PhysicsScene() {
		// delete everybody

		for (Rigidbody* rbody : rigidList)
			delete rbody;
		rigidList.clear();

		for (Staticbody* sbody : staticList)
			delete sbody;
		staticList.clear();

		//for (Kinematicbody* kbody : kinematicList)
		//	delete kbody;
		//kinematicList.clear();
	}

	void PhysicsScene::SetSubsteps(uint substeps_) {
		substeps = substeps_;
		if (substeps < 1) substeps = 1;
		if (substeps > 20) substeps = 20;
	}

	void PhysicsScene::SetTimestep(float timestep_) { 
		timestep = timestep_;
		if (timestep <= 0.001f) timestep = 0.001f;
	}

	Rigidbody* PhysicsScene::CreateRigidbody() {
		// create body
		Rigidbody* rbody = new Rigidbody();
		// add body to list
		rigidList.push_back(rbody);
		// return the body
		return rbody;
	}

	Staticbody* PhysicsScene::CreateStaticbody() {
		// create body
		Staticbody* sbody = new Staticbody();
		// add body to list
		staticList.push_back(sbody);
		// return the body
		return sbody;
	}

	void PhysicsScene::DestoryRigidbody(Rigidbody* rbody) {
		// remove from the list
		rigidList.remove_if([rbody](Rigidbody* other)->bool {
			return rbody == other;
		});
		// delete the body
		delete rbody;
	}

	void PhysicsScene::DestoryStaticbody(Staticbody* sbody) {
		// remove from the list
		staticList.remove_if([sbody](Staticbody* other)->bool {
			return sbody == other;
		});
		// delete the body
		delete sbody;
	}

	void PhysicsScene::DoStep(const float& delta) {
		// constants
		const size_t _substeps = substeps; // this is so the substeps isnt modified pert way through a physics update
		const size_t totalsteps = static_cast<size_t>(delta / timestep); // this is the number of steps that must be completed to match the framerate
		const float subdelta = delta / _substeps / totalsteps;

		// step as many times as required
		for (size_t i = 0; i < totalsteps; i++)
			DoSubstep(subdelta, _substeps);
	}

	void PhysicsScene::DoSubstep(const float& subdelta, const size_t& steps) { 
		// start looping through bodies
		for (Rigidbody* rbody : rigidList) {
			// skip if it doesnt have a shape or if simulate is false
			if ((!rbody->simulated) || (rbody->shape == nullptr)) continue;

			for (size_t i = 0; i < steps; ++i) { // this is for each substep
												 // update the bodies position and velocity
				rbody->velocity += rbody->acceleration * subdelta;
				rbody->position += rbody->velocity * subdelta;
				rbody->UpdateBounds();

				// check collisions against every rigidbody
				for (Rigidbody* other : rigidList) {
					// skip itself
					if (rbody == other) continue;
					// skip if it doesnt have a shape or if simulate is false
					if ((!other->simulated) || (other->shape == nullptr)) continue;

					// check if the bounds overlap
					if (Bounds::Intersects(rbody->bounds, other->bounds))
						DetermineRigidRigidCollision(rbody, rbody->shape, other, other->shape);
				}

				// check collisions against every staticbody
				for (Staticbody* other : staticList) {
					// skip if it doesnt have a shape or if simulate is false
					if ((!other->simulated) || (other->shape == nullptr)) continue;

					// check if the bounds overlap
					if (Bounds::Intersects(rbody->bounds, other->bounds))
						DetermineRigidStaticCollision(rbody, rbody->shape, other, other->shape);
				}

				//// check collisions against every kinematicbody
				//for (Kinematicbody* other : kinematicList) {
				//
				//	// check if the bounds overlap
				//	if (Bounds::Intersects(rbody->bounds, other->bounds))
				//		DetermineRigidKinematicCollision(rbody, rbody->shape, other, other->shape);
				//}
			}
		}
	}

	void PhysicsScene::DetermineRigidStaticCollision(
		Rigidbody* rbody,
		Shape* rShape,
		const Staticbody* sbody,
		const Shape* sShape
	) {
		// determin what kind of colliders they have
		switch (rShape->GetShapeType()) {
		case ShapeType::Circle:
			switch (sShape->GetShapeType()) {
			case ShapeType::Circle:
				Collisions::RigidCircle_StaticCircle(
					rbody,
					dynamic_cast<Circle*>(rShape),
					sbody,
					dynamic_cast<const Circle*>(sShape)
				); return;
			default: return;
			}

		default: return;
		}
	}

	void PhysicsScene::DetermineRigidRigidCollision(
		Rigidbody* rbody0,
		Shape* rShape0,
		Rigidbody* rbody1,
		Shape* rShape1
	) {
		// TODO: add functionality
	}

	//void PhysicsScene::UpdatePhysics(const float& delta, Body* body, Bounds& bounds) {
	//	if (body->type == BodyType::Dynamic) {
	//		// update position and velocity
	//		body->velocity += body->acceleration * delta;
	//		body->position += body->velocity * delta;
	//
	//		// update bounds
	//		bounds = body->GetBounds();
	//	}
	//}
	//
	//void PhysicsScene::CheckCollisions(const float& delta, Body* body, Bounds& bounds, Shape* shape) {
	//	// dont check collisions if its static
	//	if (body->type == BodyType::Static) return;
	//
	//	// loop through all bodies and check for collisions
	//	for (Node* node : body_list) {
	//		// skip self
	//		if (body == node->body) continue;
	//
	//		// the two bounds overlap
	//		if (Bounds::Intersects(bounds, node->bounds)) {
	//			// now figure out what collision function to call
	//			if (node->body->type == BodyType::Dynamic)
	//				DetermineDynamCollision(body, body->shape, node->body, node->body->shape);
	//			else
	//				DetermineStaticCollision(body, body->shape, node->body, node->body->shape);
	//		}
	//	}
	//
	//}
	//
	//void PhysicsScene::DetermineStaticCollision(
	//	Body* bodyA,
	//	Shape* shapeA,
	//	Body* bodyB,
	//	Shape* shapeB
	//) {
	//	switch (shapeA->GetShapeType()) {
	//		case ShapeType::Circle:
	//
	//			switch (shapeB->GetShapeType()) {
	//				case ShapeType::Circle:
	//					Collisions::RigidCircle_StaticCircle(
	//						bodyA,
	//						dynamic_cast<Circle*>(shapeA),
	//						bodyB,
	//						dynamic_cast<Circle*>(shapeB)
	//					); return;
	//				default: Debug::PrintError("Shape type not permitted"); return;
	//			} break;
	//
	//		default: Debug::PrintError("Shape type not permitted"); return;
	//	}
	//}
	//
	//void PhysicsScene::DetermineDynamCollision(
	//	Body* bodyA,
	//	Shape* shapeA,
	//	Body* bodyB,
	//	Shape* shapeB
	//) {
	//	switch (shapeA->GetShapeType()) {
	//		default: Debug::PrintError("Shape type not permitted"); return;
	//	}
	//}

}