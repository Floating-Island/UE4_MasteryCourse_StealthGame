#pragma once
#include "GameModeState.h"
class StateFailure :
	public GameModeState
{
public:
	StateFailure() {};
	void missionResult(AFPSGameMode* gameMode, APawn* player) { gameMode->onMissionFailure(player); };
	~StateFailure() {};
};

