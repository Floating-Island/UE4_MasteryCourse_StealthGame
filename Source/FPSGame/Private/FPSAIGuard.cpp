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

	SetReplicates(true);//to replicate spawning. When someone spawns this actor, it will tell the server to replicate it to the rest of the clients. If not set in the spawner, only the server will be able to replicate to others.
	SetReplicateMovement(true);//this actor moves, so it's necessary to replicate it's movement.
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

// Called every frame
void AFPSAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->patrolTickGoalCheck();
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

void AFPSAIGuard::idleState()
{
	this->serverIdleState();
}

void AFPSAIGuard::suspiciousState()
{
	this->serverSuspiciousState();
}

void AFPSAIGuard::alertedState()
{
	this->serverAlertedState();
}

void AFPSAIGuard::serverSuspiciousState_Implementation()
{
	this->onSuspiciousStateEvent();
}

bool AFPSAIGuard::serverSuspiciousState_Validate()
{
	return true;
}

void AFPSAIGuard::serverAlertedState_Implementation()
{
	this->onAlertedStateEvent();
}

bool AFPSAIGuard::serverAlertedState_Validate()
{
	return true;
}

void AFPSAIGuard::serverIdleState_Implementation()
{
	this->onIdleStateEvent();
}

bool AFPSAIGuard::serverIdleState_Validate()
{
	return true;
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

		//UE_LOG(LogTemp, Log, TEXT("distance to goal is %lf"), distanceToTarget); //it's something like 100 when near.

		int goalAcceptanceUnits = 110;

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

