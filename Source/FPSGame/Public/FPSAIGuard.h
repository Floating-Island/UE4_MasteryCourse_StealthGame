// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSAIGuard.generated.h"

class UPawnSensingComponent;
class AIGuardState;
class UCharacterMovementComponent;
class AAIController;


UCLASS()
class FPSGAME_API AFPSAIGuard : public ACharacter
{
	GENERATED_BODY()
private:
	AIGuardState* state;

public:
	// Sets default values for this character's properties
	AFPSAIGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

	UPROPERTY(EditInstanceOnly, Category = "Patrol AI")
		TArray<AActor*> patrolTargetCollection;
	
		AActor* currentPatrolTarget;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void initialOrientation();

	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void onIdleStateEvent();//used by state
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void onSuspiciousStateEvent();//used by state
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void onAlertedStateEvent();//used by state
};
