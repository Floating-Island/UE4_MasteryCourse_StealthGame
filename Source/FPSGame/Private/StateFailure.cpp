
#include "StateFailure.h"

GameModeState* StateFailure::singletonInstance()
{
	static StateFailure initializedInstance;
	instance = &initializedInstance;
	return instance;
}
