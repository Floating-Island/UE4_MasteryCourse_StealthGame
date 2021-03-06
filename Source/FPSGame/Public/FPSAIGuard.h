// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIGuard.generated.h"

class UPawnSensingComponent;
class AIGuardState;



UCLASS()
class FPSGAME_API AFPSAIGuard : public ACharacter
{
	GENERATED_BODY()
private:
	AIGuardState* state;
	void moveTargetPointsToQueue();

public:
	// Sets default values for this character's properties
	AFPSAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//sensing
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UPawnSensingComponent* sensingComponent;

	UFUNCTION()
		void seeingACharacter(APawn* character);

	UFUNCTION()
		void hearingANoise(APawn* noiseMaker, const FVector& noiseLocation, float volume);

	FRotator originalOrientation;

	FTimerHandle resetOrientationTimer;

	UFUNCTION()
		void resetOrientation();
	//patrolling
	UPROPERTY(EditInstanceOnly, Category = "Patrol AI")
		TArray<AActor*> targetPoints;//can't use a tqueue directly in editor. I'll use a function to pass the elements of this tarray over the tqueue 'patrolTargetCollection'

	TQueue<AActor*> patrolTargetCollection;
	
	AActor* currentPatrolTarget;

	void patrol();
	void patrolTickGoalCheck();
	void stopPatrolling();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void initialOrientation();

	/** Idle state. */
	void idleState();

	UFUNCTION(Server, Reliable, WithValidation)
		void serverIdleState();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void onIdleStateEvent();

	
	/** Idle state. */
	void suspiciousState();

	UFUNCTION(Server, Reliable, WithValidation)
		void serverSuspiciousState();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void onSuspiciousStateEvent();

	
	/** Alerted state. */
	void alertedState();

	UFUNCTION(Server, Reliable, WithValidation)
		void serverAlertedState();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void onAlertedStateEvent();
};
