#include <SDL.h>
#include "Engine/Core/Window.hpp"
#include "Engine/Core/Timer.hpp"
#include "Engine/Core/Debug.hpp"
#include "Engine/Physics/PhysicsScene.hpp"
#include "Engine/Physics/CollisionShapes/Circle.hpp"
#include "Engine/Math/FMath.hpp"
#include "Engine/Physics/CollisionShapes/Line.hpp"
#include <random>

list<Physics::Circle*> circleList;
Physics::Circle* CreateCircle() {
	Physics::Circle* circle = new Physics::Circle();
	circleList.push_back(circle);
	return circle;
}
list<Physics::Line*> lineList;
Physics::Line* CreateLine() {
	Physics::Line* line = new Physics::Line();
	lineList.push_back(line);
	return line;
}


int main(int argc, char* argv[]) {

	Window* window = new Window();
	window->OnCreate("Collision Engine Simplified", 800, 800);
	Timer* timer = new Timer();
	timer->Start();
	srand(SDL_GetTicks());
	Debug::Init();

	// physics
	Physics::PhysicsScene* scene = new Physics::PhysicsScene(4, 0.005f, 0.2f);


	// create static shapes
	{
		Physics::Staticbody* body = nullptr;
		Physics::Line* line = nullptr;
		Physics::Circle* circle = nullptr;

		// funnel left line
		body = scene->CreateStaticbody();
		line = CreateLine();
		body->SetShape(line);
		line->SetStart(Vector2(-1.0f, 1.0f));
		line->SetEnd(Vector2(0.0f, -1.0f));

		// funnel right line
		body = scene->CreateStaticbody();
		line = CreateLine();
		body->SetShape(line);
		line->SetStart(Vector2(1.0f, 1.0f));
		line->SetEnd(Vector2(0.0f, -1.0f));

		// center circle
		body = scene->CreateStaticbody();
		circle = CreateCircle();
		body->SetShape(circle);
		body->SetPosition(Vector2(0.0f, -0.2f));
		circle->SetRadius(0.1f);
	}

	float timer0 = 0.0f;
	float timer1 = 0.0f;
	size_t rigidbodycount = 0;
	while (timer0 < 30.0f) {
		timer->UpdateGameTicks();
		float delta = timer->GetDeltaTimer();
		timer0 += delta;

		{
			// draw circles
			for (Physics::Circle* shape : circleList) {
				Physics::Body* body = shape->GetBody();
				Debug::DrawCircle(body->GetPosition(), shape->GetRadius(), Color::GREEN);
				//Debug::DrawBounds(body->GetBounds());
			}
			// draw lines
			for (Physics::Line* shape : lineList) {
				Physics::Body* body = shape->GetBody();
				Debug::DrawLine(body->GetPosition() + shape->GetStart(), body->GetPosition() + shape->GetEnd(), Color::GREEN);
				//Debug::DrawBounds(body->GetBounds());
			}
		}

		// spawning bodies
		if (rigidbodycount < 36)
			timer1 += delta;
		if (timer1 > 0.6f) {
			timer1 -= 0.6f;

			// spawn
			Physics::Rigidbody* body = scene->CreateRigidbody();
			Physics::Circle* circle = CreateCircle();
			body->SetShape(circle);

			circle->SetRadius(0.06f);
			body->SetBounce(0.9f);
			body->SetPosition(Vector2(static_cast<float>(rand() % 100) / 200.0f - 0.25f, 1.0f));
			body->SetAcceleration(Vector2(0.0f, -1.1f));

			++rigidbodycount;
		}

		scene->DoStep(delta);

		printf("Sleep Count: %i || Framerate: %f\n", scene->GetSleepCount(), 1.0f / delta);

		// clear the screen
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Debug::DrawShapes();


		// swap buffers
		SDL_GL_SwapWindow(window->GetWindow());
		// wait for the end of the frame
		SDL_Delay(timer->GetSleepTime(120));
	}


	Debug::Exit();
	for (Physics::Circle* circle : circleList)
		delete circle;
	circleList.clear();
	for (Physics::Line* line : lineList)
		delete line;
	lineList.clear();
	delete window; window = nullptr;
	delete timer; timer = nullptr;
	return 0;
}
