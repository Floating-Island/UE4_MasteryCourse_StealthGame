// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	overlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Overlap Component"));
	overlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	overlapComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	overlapComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	overlapComponent->SetBoxExtent(boxExtent);
	
	RootComponent = overlapComponent;
}

// Called when the game starts or when spawned
void AFPSExtractionZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSExtractionZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

