#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "common.hpp"
#include <memory>
#include "Graphics/Window.hpp"
#include "Utility/Timer.hpp"
#include "Physics/Shapes2D.hpp"
#include <list>

class Engine {
	SINGLETON_DECLERATION(Engine)
		: isRunning(false), window(nullptr), time(nullptr), timer0(0.0f), timer1(0.0f) { }

	bool isRunning;

	Window* window;
	Timer* time;

	std::list<Physics::Circle2D*> circleList;
	std::list<Physics::Line2D*> lineList;

	float timer0;
	float timer1;

public:

	void Init();
	void Destroy();

	// starts the main loop
	void Run();

private:

	/// events

	void PollEvents();
	void Update(const float& delta);
	void Draw();

};

#endif // !ENGINE_HPP