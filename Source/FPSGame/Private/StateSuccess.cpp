
#include "StateSuccess.h"

GameModeState* StateSuccess::singletonInstance()
{
	static StateSuccess initializedInstance;
		instance = &initializedInstance;
	return instance;
}
