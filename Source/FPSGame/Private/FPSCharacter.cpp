// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FPSCharacter.h"
#include "FPSProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components\PawnNoiseEmitterComponent.h"
#include "Net/UnrealNetwork.h"


void AFPSCharacter::overlapsWithObjective(AFPSObjectiveActor* theObjective)
{
	this->isCarryingObjective = true;
}

AFPSCharacter::AFPSCharacter()
{
	// Create a CameraComponent	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->RelativeLocation = FVector(0, 0, BaseEyeHeight); // Position the camera
	CameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1PComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	Mesh1PComponent->SetupAttachment(CameraComponent);
	Mesh1PComponent->CastShadow = false;
	Mesh1PComponent->RelativeRotation = FRotator(2.0f, -15.0f, 5.0f);
	Mesh1PComponent->RelativeLocation = FVector(0, 0, -160.0f);

	// Create a gun mesh component
	GunMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	GunMeshComponent->CastShadow = false;
	GunMeshComponent->SetupAttachment(Mesh1PComponent, "GripPoint");

	//Create a NoiseEmitterComponent
	noiseEmissionComponent = CreateDefaultSubobject<UPawnNoiseEmitterComponent>(TEXT("Noise Emitter"));// now the character is able to make noise.
}


void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void AFPSCharacter::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	
	this->localPlayerLocationUpdate();
}

void AFPSCharacter::localPlayerLocationUpdate()
{
	if (!IsLocallyControlled())
	{
		FRotator playerRotation = (CameraComponent->RelativeRotation);

		
		//RemoteViewPitch is compressed, so it needs to be decompressed
		float AvailablePitchDegrees = 360.0f;//available degrees in pitch
		float AvaliableBits = 255.0f;//available amount in a uint8, the type of RemoteViewPitch

		float decompressedRotation = RemoteViewPitch * AvailablePitchDegrees / AvaliableBits;

		playerRotation.Pitch = decompressedRotation;

		CameraComponent->SetRelativeRotation(playerRotation);
	}
}


void AFPSCharacter::Fire()
{
	this->serverFire();
	/*
		if it's a client, the client will make a request to the server to run this function.
		if the server calls it, it will execute immediately.
		serverFire only runs in the server. That way, every fire will be replicated on all the clients.
		the clients requests the server to execute that function, so when the server executes it, it will be
		replicated on all the connected clients.
		This is because we made the projectile able to be replicated.
	*/
	// try and fire a projectile


	//this will be played only locally. In the coop game we're going to change them.
	// try and play the sound if specified
	if (FireSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = Mesh1PComponent->GetAnimInstance();
		if (AnimInstance)
		{
			AnimInstance->PlaySlotAnimationAsDynamicMontage(FireAnimation, "Arms", 0.0f);
		}
	}
}

//Server functions for AFPSCharacter::severFire()
//FPSCharacter.generated.h will handle headers for this functions.
//when we want to use serverFire, we use it normally.
void AFPSCharacter::serverFire_Implementation()//server implementation of AFPSCharacter::severFire()
{
	if (ProjectileClass)
	{
		FVector MuzzleLocation = GunMeshComponent->GetSocketLocation("Muzzle");
		FRotator MuzzleRotation = GunMeshComponent->GetSocketRotation("Muzzle");

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
		ActorSpawnParams.Instigator = this;// this character is the one who spawned the projectile.

		// spawn the projectile at the muzzle
		GetWorld()->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, ActorSpawnParams);
	}
}

bool AFPSCharacter::serverFire_Validate()//WithValidation
{
	return true;//until real checking is needed.
}//used in server side for sanity checks (like cheating or other things)

void AFPSCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}


void AFPSCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFPSCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFPSCharacter, isCarryingObjective);

	//DOREPLIFETIME_CONDITION(AFPSCharacter, isCarryingObjective, COND_OwnerOnly);//only the one that carries the objective will use it. Saves bandwidth
}