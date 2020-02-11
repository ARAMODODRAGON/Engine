#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "common.hpp"
#include <memory>
#include "Graphics/Window.hpp"
#include "Utility/Timer.hpp"

class Engine {
	SINGLETON_DECLERATION(Engine)
		: isRunning(false), window(nullptr), timer(nullptr) { }

	bool isRunning;

	Window* window;
	Timer* timer;

public:

	void Init();
	void Destroy();

	// starts the main loop
	void Run();

private:

	/// events

	void PollEvents();
	void Update(const float& delta);
	void PhysicsUpdate(const float& delta);
	void Draw();

};

#endif // !ENGINE_HPP