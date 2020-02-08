#include <SDL.h>
#include "Engine/Core/Window.hpp"
#include "Engine/Core/Timer.hpp"
#include "Engine/Core/Debug.hpp"
#include "Engine/Physics/PhysicsScene.hpp"
#include "Engine/Physics/Circle.hpp"
#include "Engine/Physics/Body.hpp"

int main(int argc, char* argv[]) {

	Window* window = new Window();
	window->OnCreate("Collision Engine Simplified", 800, 800);
	Timer* timer = new Timer();
	timer->Start();
	Debug::Init();

	// physics
	Physics::PhysicsScene* scene = new Physics::PhysicsScene(4);


	Physics::Body* bodyA = new Physics::Body();
	Physics::Circle* circleA = new Physics::Circle();
	{
		bodyA->position = Vector2(-0.1f, 1.0f);
		bodyA->acceleration = Vector2(0.0f, -1.0f);

		circleA->radius = 0.08f;
		bodyA->SetShape(circleA);

		bodyA->SetBodyType(Physics::BodyType::Dynamic);
	}


	Physics::Body* bodyB = new Physics::Body();
	Physics::Circle* circleB = new Physics::Circle();
	{
		bodyB->position = Vector2(0.0f, -0.5f);

		circleB->radius = 0.3f;
		bodyB->SetShape(circleB);

		bodyB->SetBodyType(Physics::BodyType::Static);
	}


	scene->AddBody(bodyA);
	scene->AddBody(bodyB);

	float timer0 = 0.0f;

	while (true) {

		bodyA->position = Vector2(0.01f, 1.0f);
		bodyA->acceleration = Vector2(0.0f, -0.8f);
		bodyA->velocity = Vector2(0.0f);
		timer0 = 0.0f;
		while (timer0 < 4.0f) {
			timer->UpdateGameTicks();
			float delta = timer->GetDeltaTimer();
			timer0 += delta;

			Debug::DrawCircle(bodyA->position, circleA->radius);
			Debug::DrawCircle(bodyB->position, circleB->radius);
			//Debug::DrawBounds(bodyA->GetBounds());
			//Debug::DrawBounds(bodyB->GetBounds());

			scene->DoStep(delta);

			// clear the screen
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			Debug::DrawShapes();


			// swap buffers
			SDL_GL_SwapWindow(window->GetWindow());
			// wait for the end of the frame
			SDL_Delay(timer->GetSleepTime(60));
		}
	}

	Debug::Exit();
	delete bodyA; bodyA = nullptr; circleA = nullptr;
	delete bodyB; bodyB = nullptr; circleB = nullptr;
	delete scene; scene = nullptr;
	delete window; window = nullptr;
	delete timer; timer = nullptr;
	return 0;
}