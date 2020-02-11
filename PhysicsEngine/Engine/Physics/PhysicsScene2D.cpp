#include "PhysicsScene2D.hpp"

namespace Physics {
	SINGLETON_DEFINITION(PhysicsScene2D)

		void PhysicsScene2D::Init(const float& timestep_, const size_t& substeps_) {
		timestep = timestep_; substeps = substeps_;
	}

	void PhysicsScene2D::Exit() {
		DestoryAllBodies();
	}

	#pragma region Creating/Destorying Bodies

	Rigidbody2D* PhysicsScene2D::CreateRigidbody() {
		Rigidbody2D* body = new Rigidbody2D();
		rigidbodyList.push_back(body);
		return body;
	}

	Staticbody2D* PhysicsScene2D::CreateStaticBody() {
		Staticbody2D* body = new Staticbody2D();
		staticbodyList.push_back(body);
		return body;
	}

	void PhysicsScene2D::DestroyRigidbody(Rigidbody2D* body) {
		rigidbodyList.remove_if([body](Rigidbody2D* rb)->bool {
			return body == rb;
		});
		delete body;
	}

	void PhysicsScene2D::DestoryStaticbody(Staticbody2D* body) {
		staticbodyList.remove_if([body](Staticbody2D* sb)->bool {
			return body == sb;
		});
		delete body;
	}

	void PhysicsScene2D::DestoryAllBodies() {
		for (Rigidbody2D* rb : rigidbodyList)
			delete rb;
		rigidbodyList.clear();

		for (Staticbody2D* sb : staticbodyList)
			delete sb;
		staticbodyList.clear();
	}

	#pragma endregion

	void PhysicsScene2D::DoStep(const float& delta) {
		// constants
		const size_t _substeps = substeps; // this is so the substeps isnt modified pert way through a physics update
		const size_t totalsteps = static_cast<size_t>(delta / timestep); // this is the number of steps that must be completed to match the framerate
		const float subdelta = timestep / _substeps;

		// step as many times as required
		for (size_t i = 0; i < totalsteps; i++)
			DoSubsteps(subdelta, _substeps);
	}

	void PhysicsScene2D::DoSubsteps(const float& fixedDelta, const size_t& substeps) {
		// start looping through bodies
		for (Rigidbody2D* rb : rigidbodyList) {
			// skip if it doesnt have a shape or if simulated is false
			if ((!rb->simulated) || (rb->shape == nullptr)) continue;

			// this is for each substep
			for (size_t i = 0; i < substeps; ++i) {
				// update the bodies position and velocity
				rb->velocity += rb->acceleration * fixedDelta;
				rb->position += rb->velocity * fixedDelta;

				// check collisions against every rigidbody
				for (Rigidbody2D* other : rigidbodyList) {
					// skip itself or if it doesnt have a shape or if simulate is false
					if (rb == other || (!other->simulated) || (other->shape == nullptr)) continue;

					// check if the bounds overlap
					//DetermineRigidRigidCollision(subdelta, rb, rb->shape, other, other->shape);
				}

				// check collisions against every staticbody
				for (Staticbody2D* other : staticbodyList) {
					// skip if it doesnt have a shape or if simulate is false
					if ((!other->simulated) || (other->shape == nullptr)) continue;

					// check if the bounds overlap
					//DetermineRigidStaticCollision(rb, rb->shape, other, other->shape);
				}
			} // substep loop
		} // main foreach loop
	}

	void PhysicsScene2D::DetermineRigidStaticCollision(Rigidbody2D* body0, const Staticbody2D* body1) { 
		switch (body0->shapeType) {
		case ShapeType2D::Circle:

			switch (body1->shapeType) {
			case ShapeType2D::Circle:
				/// TODO: add collision code here
				return;
			default: PRINT_ERROR("ShapeType2D of id:" + TEXT((int)body1->shapeType) + " is not supported"); return;
			}

			return;
		default: PRINT_ERROR("ShapeType2D of id:" + TEXT((int)body0->shapeType) + " is not supported"); return;
		}
	}

	void PhysicsScene2D::DetermineRigidRigidCollision(Rigidbody2D* body0, Rigidbody2D* body1) { }

}