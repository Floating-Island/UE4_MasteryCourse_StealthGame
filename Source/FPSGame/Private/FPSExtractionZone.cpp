// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"

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
}


void AFPSExtractionZone::handleOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent,
	int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlapped with extraction zone"));
}

