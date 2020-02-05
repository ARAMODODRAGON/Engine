#ifndef PHYSICS_SCENE_H
#define PHYSICS_SCENE_H
#include "../Common.h"
#include "../Math/Bounds.h"
class Body;

class PhysicsScene {
	// singleton
	static PhysicsScene* singleton;

	struct BNode {
		Body* body;
		Bounds bounds;
		BNode() : body(nullptr), bounds(Bounds()) { }
	};

	// a list typedef for cleaner code
	typedef list<BNode*> PhysList;

	/// TODO: replace list with RTree
	// the list of bodies and colliders
	PhysList physList;

	/// constants
	// the number of substeps that the physics step takes
	const uint substeps;

public:

	static PhysicsScene* GetSingleton();
	PhysicsScene(const uint& substeps_);
	~PhysicsScene();

	/// public events

	void DoStep(const float& delta);

	/// public functions

	void AddBody(Body* body);
	void RemoveBody(Body* body);

private:

	/// private events

	// the substep
	void DoSubstep(const float& delta);
	// updates the positions of bodies
	void SubstepPhysics(Bounds& bounds, Body* body, const float& delta);
	// does collisions between bodies
	void SubstepCollisions(BNode* node);

	/// private functions

	// checks for collisions with this body
	void CheckCollisions(Body* bodyA, Body* bodyB);

};

#endif // !PHYSICS_SCENE_H