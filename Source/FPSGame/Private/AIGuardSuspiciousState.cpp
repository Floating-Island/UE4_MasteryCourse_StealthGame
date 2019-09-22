// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"
#include "AIGuardIdleState.h"
#include "FPSAIGuard.h"

AIGuardSuspiciousState::AIGuardSuspiciousState()
{
}

AIGuardState* AIGuardSuspiciousState::singletonInstance()
{
	static AIGuardSuspiciousState initializedInstance;
	return &initializedInstance;
}

AIGuardState* AIGuardSuspiciousState::reactToNoise()
{
	return this;
}

AIGuardState* AIGuardSuspiciousState::reactToSpotting()
{
	return AIGuardAlertedState::singletonInstance();
}

AIGuardState* AIGuardSuspiciousState::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	guard->initialOrientation();
	return AIGuardIdleState::singletonInstance();
}
