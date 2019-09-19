
#include "StateFailure.h"

GameModeState* StateFailure::singletonInstance()
{
	static StateFailure initializedInstance;
	return &initializedInstance;
}
