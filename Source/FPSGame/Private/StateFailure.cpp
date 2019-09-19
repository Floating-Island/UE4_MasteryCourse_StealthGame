
#include "StateFailure.h"

GameModeState* SingletonStateFailure::singletonInstance()
{
	static SingletonStateFailure initializedInstance;
	return &initializedInstance;
}
