#include <SDL.h>
#include "Engine/GameObject.h"
#include "Engine/Component.h"
#include "Engine/Physics/Body.h"
#include "Testing/CollisionChecker.h"
#include "Testing/TestGame.h"

int main(int argc, char* argv[]) {

	TestGame* game = new TestGame();

	game->Run();

	delete game; game = nullptr;

	return 0;
}