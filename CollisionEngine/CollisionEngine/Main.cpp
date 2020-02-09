#include <SDL.h>
#include "Engine/Core/Window.hpp"
#include "Engine/Core/Timer.hpp"
#include "Engine/Core/Debug.hpp"
#include "Engine/Physics/PhysicsScene.hpp"
#include "Engine/Physics/CollisionShapes/Circle.hpp"
//#include "Engine/Physics/Body.hpp"
#include "Engine/Math/Mathf.hpp"

list<Physics::Circle*> circleList;
Physics::Circle* CreateCircle() {
	Physics::Circle* circle = new Physics::Circle();
	circleList.push_back(circle);
	return circle;
}


int main(int argc, char* argv[]) {

	Window* window = new Window();
	window->OnCreate("Collision Engine Simplified", 800, 800);
	Timer* timer = new Timer();
	timer->Start();
	Debug::Init();

	// physics
	Physics::PhysicsScene* scene = new Physics::PhysicsScene(20, 0.005f);


	Physics::Rigidbody* bodyA = scene->CreateRigidbody();
	Physics::Circle* circleA = CreateCircle();
	{
		bodyA->SetAcceleration(Vector2(0.0f, -1.1f));
		bodyA->SetBounce(0.9f);

		circleA->SetRadius(0.08f);
		bodyA->SetShape(circleA);
	}

	{
		Physics::Staticbody* sbody = nullptr;
		Physics::Circle* scircle = nullptr;


		sbody = scene->CreateStaticbody();
		scircle = CreateCircle();
		sbody->SetShape(scircle);
		sbody->SetPosition(Vector2(0.39f, -0.3f));
		sbody->SetBounce(0.0f);
		scircle->SetRadius(0.3f);


		sbody = scene->CreateStaticbody();
		scircle = CreateCircle();
		sbody->SetShape(scircle);
		sbody->SetPosition(Vector2(-0.5f, -0.3f));
		sbody->SetBounce(0.0f);
		scircle->SetRadius(0.3f);
		

		sbody = scene->CreateStaticbody();
		scircle = CreateCircle();
		sbody->SetShape(scircle);
		sbody->SetPosition(Vector2(-0.0f, -0.8f));
		sbody->SetBounce(0.0f);
		scircle->SetRadius(0.3f);

	}

	for (size_t i = 0; i < 1; ++i) {

		// reset ball position
		bodyA->SetPosition(Vector2(0.388f, 0.9f));
		bodyA->SetVelocity(Vector2::ZERO);

		float timer0 = 0.0f;
		while (timer0 < 12.5f) {
			timer->UpdateGameTicks();
			float delta = timer->GetDeltaTimer();
			timer0 += delta;

			// draw circles
			for (Physics::Circle* circle : circleList) {
				Physics::Body* body = circle->GetBody();
				Debug::DrawCircle(body->GetPosition(), circle->GetRadius());
				//Debug::DrawBounds(body->GetBounds());
			}

			//printf("pos(x:%f, y:%f)\n", bodyA->GetPosition().x, bodyA->GetPosition().y);

			scene->DoStep(delta);

			// clear the screen
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			Debug::DrawShapes();


			// swap buffers
			SDL_GL_SwapWindow(window->GetWindow());
			// wait for the end of the frame
			SDL_Delay(timer->GetSleepTime(120));
		}
	}

	Debug::Exit();
	for (Physics::Circle* circle : circleList)
		delete circle;
	circleList.clear();
	delete window; window = nullptr;
	delete timer; timer = nullptr;
	return 0;
}
