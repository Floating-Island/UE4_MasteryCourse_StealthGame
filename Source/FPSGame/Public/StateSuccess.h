#pragma once
#include "GameModeState.h"
class StateSuccess :
	public GameModeState
{
private:
	static GameModeState* instance;
	StateSuccess() {};
public:
	static GameModeState* singletonInstance();
	void missionResult(AFPSGameMode* gameMode, APawn* player) { gameMode->onMissionComplete(player); };
	~StateSuccess() {};
};

