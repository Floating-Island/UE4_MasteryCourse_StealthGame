// Fill out your copyright notice in the Description page of Project Settings.


#include "AFPSGameState.h"

void AAFPSGameState::multicastOnMissionComplete_Implementation(APawn* player, bool missionSucceded)
{
	for(FConstPawnIterator iterator = GetWorld()->GetPawnIterator(); iterator; iterator++)
	{
		APawn* pawn = iterator->Get();
		if (pawn && pawn->IsLocallyControlled())
		{
			pawn->DisableInput(nullptr);
		}
	}
}
