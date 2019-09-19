#pragma once

#include "FPSGameMode.h"

class GameModeState
{
public:
	virtual GameModeState* singletonInstance() = 0;
	virtual void missionResult(AFPSGameMode* gameMode, APawn* player) = 0;
	virtual ~GameModeState() = 0;
};

