#include "PhysicsScene.hpp"

namespace Physics {

	PhysicsScene::PhysicsScene() { }

	PhysicsScene::~PhysicsScene() {
		DestoryAllBodies();
	}

	Rigidbody* PhysicsScene::CreateRigidbody() {
		Rigidbody body;
		rigidbodyList.push_back(body);

		// get a reference to the rigidbody that was just inserted
		return &rigidbodyList.back();
	}

	Staticbody* PhysicsScene::CreateStaticbody() {
		Staticbody body;
		staticbodyList.push_back(body);

		// get a reference to the staticbody that was just inserted
		return &staticbodyList.back();
	}

	void PhysicsScene::DestroyRigidbody(Rigidbody* body) {
		rigidbodyList.remove_if([body](Rigidbody& rb)->bool {
			return &rb == body;
		});
	}

	void PhysicsScene::DestoryStaticbody(Staticbody* body) {
		staticbodyList.remove_if([body](Staticbody& rb)->bool {
			return &rb == body;
		});
	}

	void PhysicsScene::DestoryAllBodies() {
		rigidbodyList.clear();
		staticbodyList.clear();
	}

}
