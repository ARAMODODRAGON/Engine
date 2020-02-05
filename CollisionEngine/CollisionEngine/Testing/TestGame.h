#ifndef TEST_GAME_H
#define TEST_GAME_H
#include "../Engine/Core.h"
#include "../Engine/GameObject.h"

class TestGame : public Core {

public:

	// events
	virtual void Init() override;
	virtual void Exit() override;
};


#endif // !TEST_GAME_H