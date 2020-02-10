#include "PhysicsScene.hpp"
#include "../Core/Debug.hpp"
#include "Collisions.hpp"

namespace Physics {

	PhysicsScene::PhysicsScene(uint substeps_, float timestep_, float waittime_)
		: substeps(0), timestep(0.0f), waittime(waittime_) {
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

	size_t PhysicsScene::GetSleepCount() {
		size_t count = 0;

		for (Rigidbody* rb : rigidList)
			if (rb->sleepMode == SleepMode::Sleep) ++count;

		return count;
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
			// skip if it doesnt have a shape or if simulate is false or if sleeping
			if ((!rbody->simulated) || (rbody->shape == nullptr) || (rbody->sleepMode == SleepMode::Sleep)) continue;

			// this is for each substep
			for (size_t i = 0; i < steps; ++i) { 
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
						DetermineRigidRigidCollision(subdelta, rbody, rbody->shape, other, other->shape);
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
					static_cast<Circle*>(rShape),
					sbody,
					static_cast<const Circle*>(sShape)
				); return;
			case ShapeType::Line:
				Collisions::RigidCircle_StaticLine(
					rbody,
					static_cast<Circle*>(rShape),
					sbody,
					static_cast<const Line*>(sShape)
				); return;
			default: return;
			}

		default: return;
		}
	}

	void PhysicsScene::DetermineRigidRigidCollision(
		const float& delta, 
		Rigidbody* rbody0,
		Shape* rShape0,
		Rigidbody* rbody1,
		Shape* rShape1
	) {
		// determin what kind of colliders they have
		switch (rShape0->GetShapeType()) {
		case ShapeType::Circle:
			switch (rShape1->GetShapeType()) {
			case ShapeType::Circle:
				Collisions::RigidCircle_RigidCircle(
					delta,
					rbody0,
					static_cast<Circle*>(rShape0),
					rbody1,
					static_cast<Circle*>(rShape1)
				); return;
			default: return;
			}

		default: return;
		}
	}

}