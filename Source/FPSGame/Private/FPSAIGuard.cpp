// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIGuard.h"
#include "Perception\PawnSensingComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing Component"));//doesn't need an attachment, it's not a scene component. Doesn't belong to the hierarchy

	sensingComponent->OnSeePawn.AddDynamic(this, &AFPSAIGuard::seeingACharacter);//sightsense setup.
	sensingComponent->OnHearNoise.AddDynamic(this, &AFPSAIGuard::hearingANoise);//hearsense setup
}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();

}

void AFPSAIGuard::seeingACharacter(APawn* character)
{
	if (character != nullptr)
		DrawDebugSphere(GetWorld(), character->GetActorLocation(), 32.0f, 12, FColor::Yellow, false, 10.0f);//kind of visual log.
}

void AFPSAIGuard::hearingANoise(APawn* noiseMaker, const FVector& noiseLocation, float volume)
{
	DrawDebugSphere(GetWorld(), noiseLocation, 32.0f, 12, FColor::Orange, false, 10.0f);//kind of visual log.
}

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

