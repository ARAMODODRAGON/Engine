#ifndef PHYSICS_SCENE_HPP
#define PHYSICS_SCENE_HPP
#include "../Common.hpp"
#include "Body.hpp"

namespace Physics {

	class PhysicsScene {

		struct Node {
			Body* body;
			Bounds bounds;

			Node(Body* body_) : body(nullptr) {
				body = body_;
				bounds = body->GetBounds();
			}

			void UpdateBounds() {
				bounds = body->GetBounds();
			}
		};

		// the list of bodies
		list<Node*> body_list;

		// the number of substeps that must be preformed
		uint substeps;

	public:

		PhysicsScene(uint substeps);
		~PhysicsScene();

		/// setters

		void SetSubsteps(uint substeps);

		/// adding/removing bodies

		void AddBody(Body* body);
		void RemoveBody(Body* body);

		/// public events

		void DoStep(const float& delta);

	private:

		/// private events

		void UpdatePhysics(const float& delta, Body* body, Bounds& bounds);
		void CheckCollisions(const float& delta, Body* body, Bounds& bounds, Shape* shape);
		//void UpdateDynamics(const float& delta);


		/// functions

		void DetermineStaticCollision(Body* bodyA, Shape* shapeA, Body* bodyB, Shape* shapeB);
		void DetermineDynamCollision(Body* bodyA, Shape* shapeA, Body* bodyB, Shape* shapeB);

	};

}

#endif // !PHYSICS_SCENE_HPP