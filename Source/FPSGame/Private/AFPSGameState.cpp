// Fill out your copyright notice in the Description page of Project Settings.


#include "AFPSGameState.h"
#include "FPSPlayerController.h"

void AAFPSGameState::multicastOnMissionComplete_Implementation(APawn* player, bool bMissionSucceded)
{
	for(FConstPlayerControllerIterator iterator = GetWorld()->GetPlayerControllerIterator(); iterator; iterator++)
	{
		AFPSPlayerController* playerController = Cast<AFPSPlayerController>(iterator->Get());
		if (playerController && playerController->IsLocalController())
		{
			playerController->onMissionCompletion(player, bMissionSucceded);

			APawn* pawn = playerController->GetPawn();
			if(pawn)
			{
				pawn->DisableInput(playerController);
			}
		}
	}
}
