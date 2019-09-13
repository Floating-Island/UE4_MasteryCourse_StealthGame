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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		FVector boxExtent = FVector(200.0f);

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* overlapComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
