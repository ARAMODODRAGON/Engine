#ifndef PHYSICS_SCENE_H
#define PHYSICS_SCENE_H
#include "../Common.h"

class PhysicsScene {
	// a list typedef for cleaner code
	typedef list<class Body*> PhysList;

	/// TODO: replace list with RTree
	// the list of bodies and colliders
	PhysList physList;
	
	/// constants
	// the number of substeps that the physics step takes
	const int substeps;

public:

	PhysicsScene(const int& substeps);
	~PhysicsScene();

	/// public events

	void DoStep(const float& delta);

private:

	/// private events
	// updates the positions of bodies
	void SubstepPhysics(const float& delta);
	// does collisions between bodies
	void SubstepCollisions();

	/// private functions
	// checks for collisions with this body
	void CheckCollisions(Body const* body);

};

#endif // !PHYSICS_SCENE_H