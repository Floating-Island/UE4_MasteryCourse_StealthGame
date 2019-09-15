// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSLaunchPad.h"
#include "Components\BoxComponent.h"
#include "Components\DecalComponent.h"
#include "FPSCharacter.h"

// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	baseComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Base Component"));
	baseComponent->SetBoxExtent(baseExtent);
	baseComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	baseComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	baseComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	RootComponent = baseComponent;


	baseComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::overlappingWithBaseComponent);

}


void AFPSLaunchPad::overlappingWithBaseComponent(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	AFPSCharacter* player = Cast<AFPSCharacter>(otherActor);

	if (player != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("player overlapped with launch pad."));
		player->LaunchCharacter(launchImpulse, false, false);
	}
}

