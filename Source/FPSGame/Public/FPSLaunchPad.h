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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
		FVector baseExtent = FVector(20.0f, 20.0f, 5.0f);

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* baseComponent;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
