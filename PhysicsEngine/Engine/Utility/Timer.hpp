#ifndef TIMER_HPP
#define TIMER_HPP
#include "../Common.hpp"

class Timer {
private:

	// time related variables
	uint prevTicks, currentTicks;

public:
	// constructor and destructor
	Timer();
	~Timer() { }

	// member functions
	void Start();
	void UpdateGameTicks();
	float GetDeltaTimer() const;
	unsigned int GetSleepTime(const uint fps_);
	float GetCurrentTicks();
	void AdjustCurrentTime(uint timeStamp);

public:
	// delete copy and move contructors/operators
	Timer(const Timer&) = delete;
	Timer(Timer&&) = delete;
	Timer& operator=(const Timer&) = delete;
	Timer& operator=(Timer&&) = delete;
};

#endif // !TIMER_HPP