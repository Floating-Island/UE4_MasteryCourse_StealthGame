// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AFPSAIGuard;

/**
 * 
 */
class FPSGAME_API AIGuardState
{
public:
	AIGuardState();
	virtual ~AIGuardState();
	virtual AIGuardState* reactToNoise(AFPSAIGuard* guard) = 0;
	virtual AIGuardState* reactToSpotting(AFPSAIGuard* guard) = 0;
	virtual AIGuardState* goingBackToOriginalPosition(AFPSAIGuard* guard) = 0;
};
