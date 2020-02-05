#include "Core.h"

Core::Core()
	: gameobjects(list<GameObject*>())
	, window(nullptr)
	, timer(nullptr)
	, physics(nullptr)
	, isRunning(false) { }

void Core::Run() {
	Init();

	float timer0 = 0.0f;

	while (isRunning) {

		Update();

		Draw();

		timer0 += timer->GetDeltaTimer();
		if (timer0 > 30.0f) break;
	}

	Exit();
}

GameObject* Core::CreateGameObject() {
	// create a gameobject
	GameObject* go = new GameObject();
	go->OnCreate();

	// add to the list
	gameobjects.push_back(go);

	// return the gameobject
	return go;
}

void Core::Init() {
	// initialize pointers
	window = new Window(); window->OnCreate("Test", 1280, 720);
	timer = new Timer(); timer->Start();
	physics = new PhysicsScene(1);

	// the game will now run
	isRunning = true;
}

void Core::Exit() {
	// destroy the gameobjects
	if (gameobjects.size() > 0) {
		for (auto go : gameobjects) {
			delete go;
		}
		gameobjects.clear();
	}

}

void Core::Update() {
	// update timer
	timer->UpdateGameTicks();
	const float delta = timer->GetDeltaTimer();

	// update GameObjects
	if (gameobjects.size() > 0) {
		for (GameObject* go : gameobjects)
			go->Update(delta);
	}

	// update all physics
	physics->DoStep(delta);
}

void Core::Draw() {
	// clear the screen
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// render GameObjects
	if (gameobjects.size() > 0)
		for (GameObject* go : gameobjects)
			go->Draw();

	// swap buffers
	SDL_GL_SwapWindow(window->GetWindow());

	// wait for the end of the frame
	SDL_Delay(timer->GetSleepTime(60));
}

