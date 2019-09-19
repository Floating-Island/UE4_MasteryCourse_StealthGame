#pragma once
#include "GameModeState.h"
class StateSuccess :
	public GameModeState
{
public:
	StateSuccess() {};
	void missionResult(AFPSGameMode* gameMode, APawn* player) { gameMode->onMissionComplete(player); };
	~StateSuccess() {};
};

