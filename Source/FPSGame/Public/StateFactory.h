#pragma once
#include "GameModeState.h"
#include "StateFailure.h"
#include "StateSuccess.h"
class StateFactory :
	public GameModeState
{
private:
	GameModeState* currentState;

public:
	StateFactory() { currentState = SingletonStateFailure::singletonInstance(); }
	void missionResult(AFPSGameMode* gameMode, APawn* player) { currentState->missionResult(gameMode, player); };
	void success() { currentState = SingletonStateSuccess::singletonInstance();}
	void failure() { currentState = SingletonStateFailure::singletonInstance();}
};

