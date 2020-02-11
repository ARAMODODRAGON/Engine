#include "Engine.hpp"
#include "Utility/DebugDraw.hpp"

SINGLETON_DEFINITION(Engine);

void Engine::Init() {
	// create window and timer
	window = new Window();
	window->OnCreate("PhysicsEngine", 900, 900);
	timer = new Timer();
	timer->Start();

	// init debug draw
	Utility::DebugDraw::GetSingleton()->Init();
}

void Engine::Destroy() {
	// exit debug draw
	Utility::DebugDraw::GetSingleton()->Init();

	// delete window and timer
	delete window; window = nullptr;
	delete timer; timer = nullptr;
}

void Engine::Run() {
	if (isRunning) return;

	isRunning = true;
	while (isRunning) {
		// update time
		timer->UpdateGameTicks();

		// poll events
		PollEvents();

		// update
		Update(timer->GetDeltaTimer());

		// physics update
		PhysicsUpdate(timer->GetDeltaTimer());

		// draw
		Draw();
	}
}

void Engine::PollEvents() {
	SDL_Event events;
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT)
			isRunning = false;
	}
}

void Engine::Update(const float& delta) {
	Utility::DebugDraw::DrawLine(Math::float2(0.0f, 0.3f), Math::float2(0.1f, -0.3f));
}

void Engine::PhysicsUpdate(const float& delta) { }

void Engine::Draw() { 
	// clear screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Utility::DebugDraw::GetSingleton()->DrawShapes();

	// start draw


	// end draw

	// swap buffers
	SDL_GL_SwapWindow(window->GetWindow());
	// wait for the end of the frame
	SDL_Delay(timer->GetSleepTime(120));
}
