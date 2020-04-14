// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPSPlayerController.generated.h"

/**
 * the difference with the pawn is that the controller exists in both the server and the client that owns the controller.
 * Instead, the pawn exists everywhere.
 */
UCLASS()
class FPSGAME_API AFPSPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Controller")//makes it available to use as a Blueprint event.
		void onMissionCompletion(APawn* pawn, bool bMissionSucceded);
};
