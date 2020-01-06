// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSAIGuard.h"
#include "Perception\PawnSensingComponent.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "FPSGameMode.h"
#include "Engine/World.h"
#include "AIGuardStateFactory.h"
#include "Containers/Queue.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

void AFPSAIGuard::moveTargetPointsToQueue()
{
	for (AActor* target : targetPoints)
		patrolTargetCollection.Enqueue(target);
}

// Sets default values
AFPSAIGuard::AFPSAIGuard()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Sensing Component"));//doesn't need an attachment, it's not a scene component. Doesn't belong to the hierarchy

	sensingComponent->OnSeePawn.AddDynamic(this, &AFPSAIGuard::seeingACharacter);//sightsense setup.
	sensingComponent->OnHearNoise.AddDynamic(this, &AFPSAIGuard::hearingANoise);//hearsense setup

	patrolTargetCollection.Empty();//don't know if it's necessary.


}

// Called when the game starts or when spawned
void AFPSAIGuard::BeginPlay()
{
	Super::BeginPlay();
	originalOrientation = this->GetActorRotation();
	state = new AIGuardStateFactory(this);
	this->moveTargetPointsToQueue();
	this->patrol();

}

void AFPSAIGuard::seeingACharacter(APawn* character)
{
	state->reactToSpotting(this);
	this->stopPatrolling();

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

	this->stopPatrolling();
	this->SetActorRotation(distractionOrientation);

	GetWorldTimerManager().ClearTimer(resetOrientationTimer);

	GetWorldTimerManager().SetTimer(resetOrientationTimer, this, &AFPSAIGuard::resetOrientation, 3.0f, false);
}

void AFPSAIGuard::resetOrientation()
{
	state->goingBackToOriginalPosition(this);
	this->patrol();
}

void AFPSAIGuard::initialOrientation()
{
	this->SetActorRotation(originalOrientation);
}

void AFPSAIGuard::patrol()
{
	if (!patrolTargetCollection.IsEmpty())
	{
		patrolTargetCollection.Dequeue(currentPatrolTarget);
		UAIBlueprintHelperLibrary::SimpleMoveToActor(this->GetController(), currentPatrolTarget);
		patrolTargetCollection.Enqueue(currentPatrolTarget);
	}
}

void AFPSAIGuard::patrolTickGoalCheck()
{
	if (currentPatrolTarget)
	{
		FVector distanceVector = this->GetActorLocation() - currentPatrolTarget->GetActorLocation();

		float distanceToTarget = distanceVector.Size();

		int goalAcceptanceUnits = 50;

		if (distanceToTarget < goalAcceptanceUnits)
			this->patrol();
	}
}

void AFPSAIGuard::stopPatrolling()
{
	AController* guardController = this->GetController();
	if (guardController)
		guardController->StopMovement();
}

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->patrolTickGoalCheck();
}

