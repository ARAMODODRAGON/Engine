#include "PhysicsScene.hpp"
#include "../Core/Debug.hpp"
//#include "Collisions.hpp"

namespace Physics {

	PhysicsScene::PhysicsScene(uint substeps_)
		: substeps(substeps_) {
		if (substeps < 1) substeps = 1;
		if (substeps > 6) substeps = 6;
	}

	PhysicsScene::~PhysicsScene() { }

	void PhysicsScene::SetSubsteps(uint substeps_) {
		substeps = substeps_;
		if (substeps < 1) substeps = 1;
		if (substeps > 6) substeps = 6;
	}

	void PhysicsScene::AddBody(Body* body) {
		body_list.push_back(new Node(body));
	}

	void PhysicsScene::RemoveBody(Body* body) {
		body_list.remove_if([body](Node* node)-> bool {
			return node->body == body;
		});
	}

	void PhysicsScene::DoStep(const float& delta) {
		// constants
		const float subdelta = delta / substeps;
		const uint steps = substeps;

		// start looping through bodies
		for (Node* node : body_list) {
			for (size_t i = 0; i < substeps; ++i) {

				// update physics
				UpdatePhysics(subdelta, node->body, node->bounds);

				// check for and update collisions
				CheckCollisions(subdelta, node->body, node->bounds, node->body->shape);

				// update dynamics


			}
		}
	}

	void PhysicsScene::UpdatePhysics(const float& delta, Body* body, Bounds& bounds) {
		if (body->type == BodyType::Dynamic) {
			// update position and velocity
			body->velocity += body->acceleration * delta;
			body->position += body->velocity * delta;

			// update bounds
			bounds = body->GetBounds();
		}
	}

	void PhysicsScene::CheckCollisions(const float& delta, Body* body, Bounds& bounds, Shape* shape) {
		// loop through all bodies and check for collisions
		for (Node* node : body_list) {
			// skip self
			if (body == node->body) continue;

			// skip if static
			if (body->type == BodyType::Static) continue;


			// the two bounds overlap
			if (Bounds::Intersects(bounds, node->bounds)) {

				Debug::Print("Two bodies have inersected!");

				// now figure out what collision function to call
				DetermineCollision(delta, body, body->shape, node->body, node->body->shape);
			}
		}

	}

	void PhysicsScene::DetermineCollision(
		const float& delta,
		Body* bodyA,
		Shape* shapeA,
		Body* bodyB,
		Shape* shapeB
	) {
		// figure out what kind of colliders are colliding and call the correct collision function

		switch (shapeA->GetShapeType()) {
			case ShapeType::Circle:
				switch (shapeB->GetShapeType()) {
					case ShapeType::Circle:
						//if (bodyB->type == BodyType::Dynamic)
							//Collisions::Circle_DynamCircle(delta, bodyA, dynamic_cast<Circle*>(shapeA), bodyB, dynamic_cast<Circle*>(shapeB));
						//else
							//Collisions::Circle_StaticCircle(delta, bodyA, dynamic_cast<Circle*>(shapeA), bodyB, dynamic_cast<Circle*>(shapeB));
						return;
					default: Debug::PrintError("Shape type not permitted"); return;
				} break;
			default: Debug::PrintError("Shape type not permitted"); return;
		}

	}

}