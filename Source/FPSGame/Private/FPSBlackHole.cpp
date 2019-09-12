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

	attractSphereComponent = CreateDefaultSubobject < USphereComponent>(TEXT("Attract Sphere component"));//creates component 
	attractSphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//the sphere collides
	attractSphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	attractSphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);//only responds to a pawn when it overlaps
	attractSphereComponent->SetupAttachment(meshComp);//it attaches to the mesh
}

// Called when the game starts or when spawned
void AFPSBlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

