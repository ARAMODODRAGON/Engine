#include <SDL.h>
#include "Engine/common.hpp"
#include "Engine/Engine.hpp"

int main(int argc, char* argv[]) {

	Engine::GetSingleton()->Init();

	Engine::GetSingleton()->Run();

	Engine::GetSingleton()->Destroy();

	return 0;
}
