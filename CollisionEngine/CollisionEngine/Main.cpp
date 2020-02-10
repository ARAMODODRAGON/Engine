#include <SDL.h>
#include "Engine/Core/Window.hpp"
#include "Engine/Core/Timer.hpp"
#include "Engine/Core/Debug.hpp"
#include "Engine/Physics/PhysicsScene.hpp"
#include "Engine/Physics/CollisionShapes/Circle.hpp"
#include "Engine/Math/FMath.hpp"
#include "Engine/Physics/CollisionShapes/Line.hpp"

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
	Debug::Init();

	// physics
	Physics::PhysicsScene* scene = new Physics::PhysicsScene(20, 0.005f);


	Physics::Rigidbody* body = scene->CreateRigidbody();
	Physics::Circle* circle = CreateCircle();
	{
		body->SetAcceleration(Vector2(0.0f, -1.1f));
		body->SetBounce(0.9f);

		circle->SetRadius(0.08f);
		body->SetShape(circle);
	}

	{ // creating shapes
		Physics::Staticbody* sbody = nullptr;
		Physics::Circle* scircle = nullptr;
		Physics::Line* sline = nullptr;

		// right circle
		//sbody = scene->CreateStaticbody();
		//scircle = CreateCircle();
		//sbody->SetShape(scircle);
		//sbody->SetPosition(Vector2(0.39f, -0.3f));
		//sbody->SetBounce(0.0f);
		//scircle->SetRadius(0.3f);

		// left circle
		sbody = scene->CreateStaticbody();
		scircle = CreateCircle();
		sbody->SetShape(scircle);
		sbody->SetPosition(Vector2(-0.8f, 0.0f));
		sbody->SetBounce(0.0f);
		scircle->SetRadius(0.2f);

		// center circle
		//sbody = scene->CreateStaticbody();
		//scircle = CreateCircle();
		//sbody->SetShape(scircle);
		//sbody->SetPosition(Vector2(-0.0f, -0.8f));
		//sbody->SetBounce(0.0f);
		//scircle->SetRadius(0.3f);

		// line across
		sbody = scene->CreateStaticbody();
		sline = CreateLine();
		sbody->SetShape(sline);
		sline->SetStart(Vector2(1.0f, 0.4f));
		sline->SetEnd(Vector2(-0.05f, -0.0f));
		sbody->SetBounce(0.0f);
		
		// line ceiling
		sbody = scene->CreateStaticbody();
		sline = CreateLine();
		sbody->SetShape(sline);
		sline->SetStart(Vector2(-0.05f, 0.0f));
		sline->SetEnd(Vector2(1.0f, -0.53f));
		sbody->SetBounce(0.0f);

		// line across inverted
		sbody = scene->CreateStaticbody();
		sline = CreateLine();
		sbody->SetShape(sline);
		sline->SetStart(Vector2(-1.0f, -0.3f));
		sline->SetEnd(Vector2(1.0f, -0.8f));
		sbody->SetBounce(0.0f);

	}

	for (size_t i = 0; i < 1; ++i) {

		// reset ball position
		body->SetPosition(Vector2(0.5f, 1.1f));
		body->SetVelocity(Vector2::ZERO);

		float timer0 = 0.0f;
		while (timer0 < 9.5f) {
			timer->UpdateGameTicks();
			float delta = timer->GetDeltaTimer();
			timer0 += delta;

			{
				// draw circles
				for (Physics::Circle* shape : circleList) {
					Physics::Body* body = shape->GetBody();
					Debug::DrawCircle(body->GetPosition(), shape->GetRadius());
					//Debug::DrawBounds(body->GetBounds());
				}
				// draw lines
				for (Physics::Line* shape : lineList) {
					Physics::Body* body = shape->GetBody();
					Debug::DrawLine(body->GetPosition() + shape->GetStart(), body->GetPosition() + shape->GetEnd());
					//Debug::DrawBounds(body->GetBounds());
				}
			}

			//printf("pos(x:%f, y:%f)\n", bodyA->GetPosition().x, bodyA->GetPosition().y);

			scene->DoStep(delta);

			// clear the screen
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
