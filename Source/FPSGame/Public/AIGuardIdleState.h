// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "AIGuardState.h"

/**
 * 
 */
class FPSGAME_API AIGuardIdleState :
	public AIGuardState
{
private:
	AIGuardIdleState();
public:
	static AIGuardState* singletonInstance(AFPSAIGuard* guard);
	AIGuardState* reactToNoise(AFPSAIGuard* guard);
	AIGuardState* reactToSpotting(AFPSAIGuard* guard);
	AIGuardState* goingBackToOriginalPosition(AFPSAIGuard* guard);
};
