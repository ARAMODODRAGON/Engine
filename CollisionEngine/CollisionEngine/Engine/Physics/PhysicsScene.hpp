#ifndef PHYSICS_SCENE_HPP
#define PHYSICS_SCENE_HPP
#include "../Common.hpp"
#include "Bodies/Body.hpp"
#include "Bodies/Rigidbody.hpp"
#include "Bodies/Staticbody.hpp"

namespace Physics {

	class PhysicsScene {
		// the lists of bodies
		list<Rigidbody*> rigidList;
		list<Staticbody*> staticList;
		//list<Kinematicbody*> kinematicList;
		
		// the number of substeps that must be preformed
		size_t substeps;
		float timestep;

	public:

		PhysicsScene(uint substeps_, float timestep_);
		~PhysicsScene();


		/// setters

		void SetSubsteps(uint substeps_);
		// @param timestep_: minimum is 0.001f
		void SetTimestep(float timestep_);


		/// creating/destroying bodies

		Rigidbody* CreateRigidbody();
		Staticbody* CreateStaticbody();
		///Kinematicbody* CreateKinematicbody();
		void DestoryRigidbody(Rigidbody* rbody);
		void DestoryStaticbody(Staticbody* sbody);
		///void DestoryKinematicbody(Kinematicbody* kbody);

		/// public events

		void DoStep(const float& delta);


	private:

		/// private events

		void DoSubstep(const float& subdelta, const size_t& steps);


		/// private functions

		void DetermineRigidStaticCollision(Rigidbody* rbody, Shape* rShape, const Staticbody* sbody, const Shape* sShape);
		void DetermineRigidRigidCollision(Rigidbody* rbody0, Shape* rShape0, Rigidbody* rbody1, Shape* rShape1);
		
	};

}

#endif // !PHYSICS_SCENE_HPP