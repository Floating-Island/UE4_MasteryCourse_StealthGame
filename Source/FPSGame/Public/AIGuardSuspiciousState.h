// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGuardState.h"

/**
 * 
 */
class FPSGAME_API AIGuardSuspiciousState : public AIGuardState
{
private:
	AIGuardSuspiciousState();
public:
	static AIGuardState* singletonInstance();
	AIGuardState* reactToNoise();
	AIGuardState* reactToSpotting();
	AIGuardState* goingBackToOriginalPosition(AFPSAIGuard* guard);
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void static onSuspiciousStateEvent();
};
