// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSBlackHole.h"

#include <Components\StaticMeshComponent.h>
#include <Components\SphereComponent.h>//the forward declaration from FPSBlackHole.h it's for faster compiling but here there's actual use of SphereComponent
#include <Kismet/GameplayStatics.h>

// Sets default values
AFPSBlackHole::AFPSBlackHole()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("Mesh Component"));//creates component 
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);// the mesh doesn't collide
	RootComponent = meshComp;

	attractionSphereComponent = CreateDefaultSubobject < USphereComponent>(TEXT("Attract Sphere component"));//creates component 
	attractionSphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//the sphere collides
	attractionSphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	attractionSphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);//only responds to a pawn when it overlaps
	attractionSphereComponent->SetupAttachment(meshComp);//it attaches to the mesh

	vanishingSphereComponent = CreateDefaultSubobject < USphereComponent>(TEXT("Vanishing Sphere component"));//creates component 
	vanishingSphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//the sphere collides
	vanishingSphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	vanishingSphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);//only responds to a pawn when it overlaps
	vanishingSphereComponent->SetupAttachment(meshComp);//it attaches to the mesh

	vanishingSphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AFPSBlackHole::overlappingWithVanishingSphere);


}

// Called when the game starts or when spawned
void AFPSBlackHole::BeginPlay()
{
	Super::BeginPlay();
}

void AFPSBlackHole::overlappingWithAttractionSphere()
{
	TArray<UPrimitiveComponent*> CollectedActors;
	attractionSphereComponent->GetOverlappingComponents(CollectedActors);//get all the actors that overlap with the attraction sphere.
	for (UPrimitiveComponent* actor : CollectedActors)
		if (actor->IsSimulatingPhysics())
			actor->AddRadialImpulse(this->GetActorLocation(), attractionSphereComponent->GetScaledSphereRadius(), forceApplied, ERadialImpulseFalloff::RIF_Constant, false);
}
void AFPSBlackHole::overlappingWithVanishingSphere(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
{
	if (otherActor)
		otherActor->Destroy();
}

// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->overlappingWithAttractionSphere();
	//adds a radial impulse to every actor inside the sphere radius.
	//the force comes from within the BlackHole location.
	//the force is negative because we want to pull the objects inside.

}


