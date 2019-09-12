// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSBlackHole.generated.h"

class USphereComponent;//forward declaration. Better at compiling, no logic here.

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSBlackHole();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")//UE4 now is able to see and edit this
		UStaticMeshComponent* meshComp;//to be able to show it.

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* attractionSphereComponent;//to be able to apply to it collission

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float forceApplied = -7000.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
