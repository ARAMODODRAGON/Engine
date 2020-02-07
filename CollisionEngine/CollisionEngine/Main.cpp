#include <SDL.h>
#include "Engine/Core/Window.hpp"
#include "Engine/Core/Timer.hpp"

int main(int argc, char* argv[]) {

	Window* window = new Window();
	window->OnCreate("Collision Engine Simplified", 1280, 720);
	Timer* timer = new Timer();
	timer->Start();


	
	delete window; window = nullptr;
	delete timer; timer = nullptr;
	return 0;
}