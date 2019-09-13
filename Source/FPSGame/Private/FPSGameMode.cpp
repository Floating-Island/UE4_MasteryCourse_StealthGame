// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

AFPSGameMode::AFPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSHUD::StaticClass();
}

void AFPSGameMode::missionComplete(APawn* player)
{
	if (player)
	{
		player->DisableInput(nullptr);

		if (SpectatorViewpointClass)
		{
			TArray<AActor*> actorsInGame;
			UGameplayStatics::GetAllActorsOfClass(this, SpectatorViewpointClass, actorsInGame);//get all actors of SpectatorViewpointClass class in the game.

			AActor* spectator;
			if (actorsInGame.Num() > 0)
			{
				spectator = actorsInGame[0];

				APlayerController* missionPlayerController = Cast<APlayerController>(player->GetController());//get the player controller
				if (missionPlayerController)
					missionPlayerController->SetViewTargetWithBlend(spectator, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);//asign the view target to another actor.
			}
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("SpectatorViewpointClass is nullptr. Update GameMode class. Unable to change view target."));

	}
	this->onMissionComplete(player);


}
