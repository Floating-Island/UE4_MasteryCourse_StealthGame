#pragma once
#include "GameModeState.h"
class StateSuccess :
	public GameModeState
{
private:
	GameModeState* instance = nullptr;
	StateSuccess() {};
public:
	GameModeState* singletonInstance();
	void missionResult(AFPSGameMode* gameMode, APawn* player) { gameMode->onMissionComplete(player); };
	~StateSuccess() {};
};

