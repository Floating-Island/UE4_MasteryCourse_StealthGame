
#include "StateSuccess.h"

GameModeState* StateSuccess::singletonInstance()
{
	static StateSuccess initializedInstance;
	return &initializedInstance;
}
