// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSLaunchPad.h"
#include "Components\BoxComponent.h"
#include "Components\DecalComponent.h"

// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	baseComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Base Component"));
	baseComponent->SetBoxExtent(baseExtent);

	RootComponent = baseComponent;

	decalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal Component"));
	decalComponent->DecalSize = baseComponent->GetScaledBoxExtent();
	decalComponent->SetupAttachment(RootComponent);//materials will be applied at the RootComponent location.



}

// Called when the game starts or when spawned
void AFPSLaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSLaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

