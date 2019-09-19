
#include "StateSuccess.h"

GameModeState* StateSuccess::singletonInstance()
{
	if (instance == nullptr)
		instance = new StateSuccess();
	return instance;
}
