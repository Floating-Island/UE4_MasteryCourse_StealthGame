#pragma once
#include "GameModeState.h"
class SingletonStateSuccess :
	public GameModeState
{
private:
	SingletonStateSuccess() {};
public:
	static GameModeState* singletonInstance();
	void missionResult(AFPSGameMode* gameMode, APawn* player) { };
	~SingletonStateSuccess() {};
};

