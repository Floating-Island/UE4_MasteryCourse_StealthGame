#pragma once
#include "GameModeState.h"
class StateFailure :
	public GameModeState
{
private:
	static GameModeState* instance = nullptr;
	StateFailure() {};
public:
	static GameModeState* singletonInstance();
	void missionResult(AFPSGameMode* gameMode, APawn* player) { gameMode->onMissionFailure(player); };
	~StateFailure() {};
};

