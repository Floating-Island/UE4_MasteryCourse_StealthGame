// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectiveActor.h"

#include <Components\StaticMeshComponent.h>
#include <Components\SphereComponent.h>


// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComp = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("Mesh Component"));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);// the mesh doesn't collide
	RootComponent = meshComp;

	sphereComp = CreateDefaultSubobject < USphereComponent>(TEXT("Sphere component"));
	sphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//the sphere collides
	sphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);//only responses to a pawn when it overlaps
	sphereComp->SetupAttachment(meshComp);
}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFPSObjectiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

