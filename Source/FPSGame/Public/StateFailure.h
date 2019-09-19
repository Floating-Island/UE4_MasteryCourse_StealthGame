#pragma once
#include "GameModeState.h"
class StateFailure :
	public GameModeState
{
private:
	GameModeState* instance = nullptr;
	StateFailure() {};
public:
	GameModeState* singletonInstance();
	void missionResult(AFPSGameMode* gameMode, APawn* player) { gameMode->onMissionFailure(player); };
	~StateFailure() {};
};

