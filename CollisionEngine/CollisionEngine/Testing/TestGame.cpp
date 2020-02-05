#include "TestGame.h"
#include "CollisionChecker.h"
#include "../Engine/Physics/Transform.h"

void TestGame::Init() {
	Core::Init();

	GameObject* go = nullptr;
	CollisionChecker* cc = nullptr;

	/// create gameobjects

	// the moving gameobject
	go = CreateGameObject();
	if (go) cc = go->CreateComponent<CollisionChecker>();
	go->GetTransform()->SetLocalPosition(vec2(-0.9f, 0.0f));
	if (cc) cc->SetVelocity(vec2(0.7f, 0.0f));

	go = nullptr;
	cc = nullptr;

	// the nonmoving GO
	go = CreateGameObject();
	if (go) cc = go->CreateComponent<CollisionChecker>();
	if (cc) cc->SetVelocity(vec2(0.0f, 0.0f));

}

void TestGame::Exit() {
	Core::Exit();
}
