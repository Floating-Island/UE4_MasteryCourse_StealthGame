// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Spectating")//editable in the editor
	TSubclassOf<AActor> SpectatorViewpointClass;//spectator class

public:

	AFPSGameMode();
	void missionComplete(APawn* pawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "Game Mode")//makes it available to use as a Blueprint event.
	void onMissionComplete(APawn* pawn);
};



