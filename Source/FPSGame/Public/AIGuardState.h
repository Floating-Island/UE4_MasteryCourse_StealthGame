// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FPSGAME_API AIGuardState
{
public:
	AIGuardState();
	virtual ~AIGuardState();
	virtual AIGuardState* reactToNoise() = 0;
	virtual AIGuardState* reactToSpotting() = 0;
	virtual AIGuardState* goingBackToOriginalPosition() = 0;
};
