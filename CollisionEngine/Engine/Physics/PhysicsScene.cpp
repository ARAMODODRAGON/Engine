#include "PhysicsScene.h"

PhysicsScene::PhysicsScene(const int& substeps_)
	: substeps(substeps_), physList(PhysList()) { }

PhysicsScene::~PhysicsScene() {


	
}

void PhysicsScene::DoStep(const float& delta) {

}

void PhysicsScene::SubstepPhysics(const float& delta) {

}

void PhysicsScene::SubstepCollisions() {

}

void PhysicsScene::CheckCollisions(Body const* body) {

}
