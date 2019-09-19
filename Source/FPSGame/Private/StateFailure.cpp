
#include "StateFailure.h"

GameModeState* StateFailure::singletonInstance()
{
	if (instance == nullptr)
		instance = new StateFailure();
	return instance;
}
