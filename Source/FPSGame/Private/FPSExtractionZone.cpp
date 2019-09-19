// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSCharacter.h"
#include "FPSGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
	overlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Component"));
	overlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	overlapComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	overlapComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	overlapComponent->SetBoxExtent(boxExtent);

	RootComponent = overlapComponent;

	overlapComponent->SetHiddenInGame(false);//now shows edges of the cube in UE Editor while playing

	overlapComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::handleOverlap);

	decalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal Component"));
	decalComponent->DecalSize = overlapComponent->GetScaledBoxExtent();
	decalComponent->SetupAttachment(RootComponent);//materials will be applied at the RootComponent location.
}


void AFPSExtractionZone::handleOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent,
	int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{


	AFPSCharacter* player = Cast<AFPSCharacter>(otherActor);

	if (player == nullptr)
		return;

	UE_LOG(LogTemp, Log, TEXT("Overlapped with extraction zone!"));
	if (player->isCarryingObjective)
	{
		AFPSGameMode* gameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());//GetWorld()->GetAuthGameMode() will return nullptr on a client
		if (gameMode)
		{
			gameMode->missionComplete(player, true);
		}
	}
	else
		UGameplayStatics::PlaySound2D(this, objectiveMissingSound);//UGameplayStatics is a Singleton and static
}

