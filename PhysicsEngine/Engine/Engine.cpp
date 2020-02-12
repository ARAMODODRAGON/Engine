#include "Engine.hpp"
#include "Utility/DebugDraw.hpp"
#include "Physics/PhysicsScene2D.hpp"
#include <random>
using Physics::PhysicsScene2D;

SINGLETON_DEFINITION(Engine);

void Engine::Init() {
	// create window and timer
	window = new Window();
	window->OnCreate("PhysicsEngine", 900, 900);
	time = new Timer();
	time->Start();

	// init debug draw
	Utility::DebugDraw::GetSingleton()->Init();
	// init physics scene
	PhysicsScene2D::GetSingleton()->Init(0.005f, 4);

	// setup the static shapes
	{
		Physics::Staticbody2D* sb = nullptr;
		Physics::Line2D* line = nullptr;
		Physics::Circle2D* circle = nullptr;

		// funnel left line
		sb = PhysicsScene2D::GetSingleton()->CreateStaticBody();
		line = sb->SetShape<Physics::Line2D>();
		lineList.push_back(line);
		line->start = (Math::float2(-1.0f, 1.0f));
		line->end = (Math::float2(0.0f, -1.0f));

		// funnel right line
		sb = PhysicsScene2D::GetSingleton()->CreateStaticBody();
		line = sb->SetShape<Physics::Line2D>();
		lineList.push_back(line);
		line->start = (Math::float2(1.0f, 1.0f));
		line->end = (Math::float2(0.0f, -1.0f));


		// center circle
		sb = PhysicsScene2D::GetSingleton()->CreateStaticBody();
		sb->SetPosition(Math::float2(0.0f, -0.2f));
		circle = sb->SetShape<Physics::Circle2D>();
		circleList.push_back(circle);
		circle->radius = (0.1f);

	}
}

void Engine::Destroy() {
	// exit debug draw
	Utility::DebugDraw::GetSingleton()->Exit();
	// exit physics scene
	PhysicsScene2D::GetSingleton()->Exit();

	// delete window and timer
	delete window; window = nullptr;
	delete time; time = nullptr;
}

void Engine::Run() {
	// if this function gets called again for whatever reason then it wont try to run again
	if (isRunning) return;

	isRunning = true;
	while (isRunning) {
		// update time
		time->UpdateGameTicks();

		//PRINT("Framerate: " + TEXT(1.0f / time->GetDeltaTimer()));

		// poll events
		PollEvents();

		// update
		Update(time->GetDeltaTimer());

		// physics update
		PhysicsScene2D::GetSingleton()->DoStep(time->GetDeltaTimer());

		// draw
		Draw();
	}
}

void Engine::PollEvents() {
	SDL_Event events;
	while (SDL_PollEvent(&events)) {
		if (events.type == SDL_QUIT) // closing window
			isRunning = false;
		if (events.type == SDL_WINDOWEVENT) // pausing the game when the window moves
			time->AdjustCurrentTime(events.window.timestamp);
	}
}

void Engine::Update(const float& delta) {
	timer0 += delta;
	if (timer0 > 60.0f) isRunning = false;

	timer1 += delta;
	if (timer1 > 0.6f) {
		timer1 -= 0.6f;

		Physics::Rigidbody2D* rb = PhysicsScene2D::GetSingleton()->CreateRigidbody();
		Physics::Circle2D* c = rb->SetShape<Physics::Circle2D>();

		rb->SetPosition(Math::float2(static_cast<float>(rand() % 100) / 200.0f - 0.25f, 1.0f));
		rb->SetAcceleration(Math::float2(0.0f, -1.1f));
		c->radius = 0.06f;

		circleList.push_back(c);
	}


}

void Engine::Draw() {
	// clear screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Utility::DebugDraw::GetSingleton()->DrawShapes();

	// start draw
	for (Physics::Circle2D* c : circleList)
		Utility::DebugDraw::DrawCircle(c->GetBody()->GetPosition(), c->radius);
	for (Physics::Line2D* l : lineList)
		Utility::DebugDraw::DrawLine(l->start, l->end);

	// end draw

	// swap buffers
	SDL_GL_SwapWindow(window->GetWindow());
	// wait for the end of the frame
	SDL_Delay(time->GetSleepTime(120));
}
