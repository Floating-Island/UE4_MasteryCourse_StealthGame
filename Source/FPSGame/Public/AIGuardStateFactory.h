// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGuardState.h"

/**
 * 
 */
class FPSGAME_API AIGuardStateFactory : public AIGuardState
{
private:
	AIGuardState* state;
public:
	AIGuardStateFactory();
	AIGuardState* reactToNoise();
	AIGuardState* reactToSpotting();
	AIGuardState* goingBackToOriginalPosition(AFPSAIGuard* guard);

};
