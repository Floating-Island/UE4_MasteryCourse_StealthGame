// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectiveActor.h"

#include <Components\StaticMeshComponent.h>
#include <Components\SphereComponent.h>
#include <Kismet/GameplayStatics.h>
#include "FPSCharacter.h"


// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
	meshComp = CreateDefaultSubobject < UStaticMeshComponent>(TEXT("Mesh Component"));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);// the mesh doesn't collide
	RootComponent = meshComp;

	sphereComp = CreateDefaultSubobject < USphereComponent>(TEXT("Sphere component"));
	sphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);//the sphere collides
	sphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);//only responds to a pawn when it overlaps
	sphereComp->SetupAttachment(meshComp);

	SetReplicates(true);//now the objective spawning will be replicated.
}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	playEffect();
}

void AFPSObjectiveActor::playEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}

void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	playEffect();

	serverDestroyOnOverlap(OtherActor);

}

void AFPSObjectiveActor::serverDestroyOnOverlap(AActor* OtherActor)
{
	if (Role == ROLE_Authority)
	{
		AFPSCharacter* thePlayer = Cast<AFPSCharacter>(OtherActor);
		if (thePlayer)
		{
			thePlayer->overlapsWithObjective(this);
			Destroy();
		}
	}
}

