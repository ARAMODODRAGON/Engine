#ifndef PHYSICS_SCENE_HPP
#define PHYSICS_SCENE_HPP
#include <list>
using std::list;
#include "Shapes.hpp"
#include "Bodies.hpp"

namespace Physics {

	class PhysicsScene {

		// bodies
		list<Rigidbody> rigidbodyList;
		list<Staticbody> staticbodyList;


	public:

		PhysicsScene();
		~PhysicsScene();

		/// creating bodies

		Rigidbody* CreateRigidbody();
		Staticbody* CreateStaticbody();

		/// destroying bodies

		void DestroyRigidbody(Rigidbody* body);
		void DestoryStaticbody(Staticbody* body);
		void DestoryAllBodies();

		/// functions
		size_t RigidListSize() { return rigidbodyList.size(); }
		size_t StaticListSize() { return staticbodyList.size(); }

	};

}

#endif // !PHYSICS_SCENE_HPP