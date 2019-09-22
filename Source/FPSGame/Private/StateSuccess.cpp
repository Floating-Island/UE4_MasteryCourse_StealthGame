
#include "StateSuccess.h"

GameModeState* SingletonStateSuccess::singletonInstance()
{
	static SingletonStateSuccess initializedInstance;
	return &initializedInstance;
}
