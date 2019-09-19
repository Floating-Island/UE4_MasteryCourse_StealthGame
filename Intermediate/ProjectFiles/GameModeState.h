#pragma once

#include "FPSGameMode.h"

class GameModeState
{
public:
	virtual void missionResult(AFPSGameMode* gameMode, APawn* player) = 0;
};

