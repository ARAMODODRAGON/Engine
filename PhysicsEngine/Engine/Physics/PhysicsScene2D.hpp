#ifndef PHYSICS_SCENE2D_HPP
#define PHYSICS_SCENE2D_HPP
#include "../common.hpp"
#include "Bodies2D.hpp"
#include <list>
#include "../Math/FloatVector.hpp"

namespace Physics {

	class PhysicsScene2D {
		SINGLETON_DECLERATION(PhysicsScene2D)
			: timestep(0.0f), substeps(1), totaldelta(0.0f) { }

		std::list<Rigidbody2D*> rigidbodyList;
		std::list<Staticbody2D*> staticbodyList;

		float timestep;
		size_t substeps;
		float totaldelta;

	public:

		void Init(const float& timestep_, const size_t& substeps_);
		void Exit();

		/// functions

		Rigidbody2D* CreateRigidbody();
		Staticbody2D* CreateStaticBody();
		void DestroyRigidbody(Rigidbody2D* body);
		void DestoryStaticbody(Staticbody2D* body);
		void DestoryAllBodies();

		/// setters

		void SetTimestep(const float& timestep_) {
			timestep = timestep_;
			if (timestep <= 0.0f) timestep = 0.0001f;
		}
		void SetSubsteps(size_t substeps_) {
			if (substeps_ == 0) substeps_ = 1;
			//if (substeps_ > 20) substeps_ = 20;
			substeps = substeps_;
		}

		/// getters

		float GetTimestep() { return timestep; }
		size_t GetSubsteps() { return substeps; }
		size_t GetRigidbodyCount() { return rigidbodyList.size(); }
		size_t GetStaticbodyCount() { return staticbodyList.size(); }

		/// events

		void DoStep(const float& delta);

	private:

		void DoSubsteps(const float& fixedDelta, const size_t& substeps);
		void DetermineRigidStaticCollision(Rigidbody2D* body0, const Staticbody2D* body1);
		void DetermineRigidRigidCollision(Rigidbody2D* body0, Rigidbody2D* body1, const float& delta);
	};

}

#endif // !PHYSICS_SCENE2D_HPP