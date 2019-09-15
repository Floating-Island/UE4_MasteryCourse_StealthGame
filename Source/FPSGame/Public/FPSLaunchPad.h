// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSLaunchPad.generated.h"

class UBoxComponent;//forward declaration

UCLASS()
class FPSGAME_API AFPSLaunchPad : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSLaunchPad();

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		FVector baseExtent = FVector(80.0f, 80.0f, 5.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		FVector launchHeightImpulse = FVector(0.0f, 0.0f, 1000.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		int launchVelocityImpulse = 1000;

	UPROPERTY(VisibleAnywhere, Category = "Components")//UE4 now is able to see and edit this
		UStaticMeshComponent* baseMesh;//to be able to show it.

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* baseComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")//UE4 now is able to see and edit this
		UStaticMeshComponent* surfaceMesh;//to be able to show it.

	UFUNCTION()
		void overlappingWithBaseComponent(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent,
			int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult);


public:


};
