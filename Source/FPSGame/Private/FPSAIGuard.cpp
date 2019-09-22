// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIGuard.h"
#include "Perception\PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "FPSGameMode.h"
#include "Engine/World.h"
#include "AIGuardStateFactory.h"

// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing Component"));//doesn't need an attachment, it's not a scene component. Doesn't belong to the hierarchy

	sensingComponent->OnSeePawn.AddDynamic(this, &AFPSAIGuard::seeingACharacter);//sightsense setup.
	sensingComponent->OnHearNoise.AddDynamic(this, &AFPSAIGuard::hearingANoise);//hearsense setup

	state = new AIGuardStateFactory(this);
}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	originalOrientation = this->GetActorRotation();

}

void AFPSAIGuard::seeingACharacter(APawn* character)
{
	state->reactToSpotting(this);
	if (character != nullptr)
		DrawDebugSphere(GetWorld(), character->GetActorLocation(), 32.0f, 12, FColor::Yellow, false, 10.0f);//kind of visual log.
	//next should be in an extracted function
	AFPSGameMode* gameMode = Cast<AFPSGameMode>(GetWorld()->GetAuthGameMode());//GetWorld()->GetAuthGameMode() will return nullptr on a client
	if (gameMode)
	{
		gameMode->failure();
		gameMode->missionEnded(character);
	}
		
}

void AFPSAIGuard::hearingANoise(APawn* noiseMaker, const FVector& noiseLocation, float volume)
{
	state->reactToNoise(this);
	DrawDebugSphere(GetWorld(), noiseLocation, 32.0f, 12, FColor::Orange, false, 10.0f);//kind of visual log.

	FVector distractionDirection = noiseLocation - this->GetActorLocation();
	distractionDirection.Normalize();

	FRotator distractionOrientation = FRotationMatrix::MakeFromX(distractionDirection).Rotator();

	distractionOrientation.Pitch = 0.0f;//only yaw is wanted
	distractionOrientation.Roll = 0.0f;//only yaw is wanted


	this->SetActorRotation(distractionOrientation);

	GetWorldTimerManager().ClearTimer(resetOrientationTimer);

	GetWorldTimerManager().SetTimer(resetOrientationTimer, this, &AFPSAIGuard::resetOrientation, 3.0f, false);
}

void AFPSAIGuard::resetOrientation()
{
	state->goingBackToOriginalPosition(this);
}

void AFPSAIGuard::initialOrientation()
{
	this->SetActorRotation(originalOrientation);
}

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

