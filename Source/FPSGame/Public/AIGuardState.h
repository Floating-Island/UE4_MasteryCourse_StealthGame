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
	~AIGuardState();
	virtual void reactToNoise() = 0;
	virtual void reactToSpotting() = 0;
	virtual void goingBackToOriginalPosition() = 0;
};
