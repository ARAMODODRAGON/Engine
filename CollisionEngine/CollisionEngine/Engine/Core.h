#ifndef CORE_H
#define CORE_H

#include "Common.h"
#include "GameObject.h"
#include "Graphics/Window.h"
#include "Timer.h"
#include "Physics/PhysicsScene.h"

class Core {

	// game object list
	list<GameObject*> gameobjects;

	/// variables
	Window* window;
	Timer* timer;
	PhysicsScene* physics;

	bool isRunning;

public:

	Core();
	~Core() { Exit(); }

	// starts the engine
	virtual void Run();

	/// creation functions
	GameObject* CreateGameObject();

	// private events
	virtual void Init();
	virtual void Exit();
	virtual void Update();
	virtual void Draw();


};

#endif // !CORE_H