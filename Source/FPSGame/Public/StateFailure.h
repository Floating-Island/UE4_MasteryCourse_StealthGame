#pragma once
#include "GameModeState.h"
class SingletonStateFailure :
	public GameModeState
{
private:
	SingletonStateFailure() {};
public:
	static GameModeState* singletonInstance();
	void missionResult(AFPSGameMode* gameMode, APawn* player) { };
	~SingletonStateFailure() {};
};

