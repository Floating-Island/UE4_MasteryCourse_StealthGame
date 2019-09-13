// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

class UBoxComponent;//forward declaration

UCLASS()
class FPSGAME_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSExtractionZone();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		FVector boxExtent = FVector(200.0f);

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* overlapComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UDecalComponent* decalComponent;

	UFUNCTION()
		void handleOverlap(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent,
			int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);

	UPROPERTY(EditDefaultsOnly, Category = "Sounds")
	USoundBase* objectiveMissingSound;

public:

};
