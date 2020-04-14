// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPSGameMode.generated.h"

class StateFactory;

UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Spectating")//editable in the editor
		TSubclassOf<AActor> SpectatorViewpointClass;//spectator class

	StateFactory *gameState;

public:

	AFPSGameMode();
	void missionEnded(APawn* pawn, bool bMissionSucceded);

	UFUNCTION(BlueprintImplementableEvent, Category = "Game Mode")//makes it available to use as a Blueprint event.
		void onMissionCompletion(APawn* pawn, bool bMissionSucceded);
};



