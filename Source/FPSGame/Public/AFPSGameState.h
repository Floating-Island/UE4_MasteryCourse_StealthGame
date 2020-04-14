// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AFPSGameState.generated.h"

/**
 * used to replicate things from GameMode because GameMode doesn't allow replication (it allways runs only on server).
 */
UCLASS()
class FPSGAME_API AAFPSGameState : public AGameStateBase
{
	GENERATED_BODY()



public:

	UFUNCTION(NetMulticast, Reliable)
		void multicastOnMissionComplete(APawn* player, bool missionSucceded);
};
