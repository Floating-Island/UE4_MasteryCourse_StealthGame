// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AFPSProjectile::AFPSProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);	// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
	//networking:
	SetReplicates(true);//to replicate spawning. When someone spawns this actor, it will tell the server to replicate it to the rest of the clients. If not set in the spawner, only the server will be able to replicate to others.
	SetReplicateMovement(true);//this actor moves, so it's necessary to replicate it's movement.
}


void AFPSProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
	
	if (Role == ROLE_Authority)//if this is the server, then execute this:
	{
		/*
			we want the server to tell the clients what to do,
			 so the server makes the noise and replicates to clients.
			 And the server destroys an object that clients will then destroy in their side.
			 Clients only simulate what the server tells them to.
		*/
		MakeNoise(1.0f, Instigator);//instigator is the one responsible for damage deal. In this case is used to make noise.
	//Instigator has a UNoiseEmitterComponent so it's nice to use.
		Destroy();//only the server has the authority to destroy it.
	}
}