// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSLaunchPad.h"
#include "Components\BoxComponent.h"
#include "Components\StaticMeshComponent.h"
#include <Kismet/GameplayStatics.h>
#include "FPSCharacter.h"

// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	baseMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = baseMesh;

	surfaceMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Surface Mesh"));
	surfaceMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	surfaceMesh->SetupAttachment(RootComponent);

	baseComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Base Component"));
	baseComponent->SetBoxExtent(baseExtent);
	baseComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	baseComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	baseComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	baseComponent->SetupAttachment(RootComponent);

	baseComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::overlappingWithBaseComponent);

}


void AFPSLaunchPad::overlappingWithBaseComponent(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	AFPSCharacter* player = Cast<AFPSCharacter>(otherActor);

	if (player != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("player overlapped with launch pad!"));
		this->launchEffect();
		player->LaunchCharacter(this->totalImpulse(), true, false);
	}
	else
		if (otherComponent != nullptr && otherComponent->IsSimulatingPhysics())
		{
			UE_LOG(LogTemp, Log, TEXT("component overlapped with launch pad!"));
			this->launchEffect();
			otherComponent->AddImpulse(this->totalImpulse(), NAME_None, true);
		}
}

void AFPSLaunchPad::launchEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, launchFX, this->GetActorLocation());
}

FVector AFPSLaunchPad::totalImpulse()
{
	FVector impulseDirection = surfaceMesh->GetForwardVector();
	return impulseDirection * launchVelocityImpulse + launchHeightImpulse;
}

