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
	StateFactory() { currentState = &StateFailure(); }
	void missionResult(AFPSGameMode* gameMode, APawn* player) { currentState->missionResult(gameMode, player); };
	void success() { currentState = &StateSuccess(); }
	void failure() { currentState = &StateFailure(); }
};

