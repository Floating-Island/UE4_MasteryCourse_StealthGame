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
	StateFactory() { currentState = new StateFailure(); }
	void missionResult(AFPSGameMode* gameMode, APawn* player) { currentState->missionResult(gameMode, player); };
	void success() { currentState = new StateSuccess(); }
	void failure() { currentState = new StateFailure(); }
};

