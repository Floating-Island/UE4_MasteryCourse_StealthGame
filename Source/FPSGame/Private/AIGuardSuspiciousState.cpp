// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"
#include "AIGuardIdleState.h"
#include "FPSAIGuard.h"

AIGuardSuspiciousState::AIGuardSuspiciousState()
{
}

AIGuardState* AIGuardSuspiciousState::singletonInstance(AFPSAIGuard* guard)
{
	static AIGuardSuspiciousState initializedInstance;
	guard->onSuspiciousStateEvent();
	return &initializedInstance;
}

AIGuardState* AIGuardSuspiciousState::reactToNoise(AFPSAIGuard* guard)
{
	return this;
}

AIGuardState* AIGuardSuspiciousState::reactToSpotting(AFPSAIGuard* guard)
{
	return AIGuardAlertedState::singletonInstance(guard);
}

AIGuardState* AIGuardSuspiciousState::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	guard->initialOrientation();
	return AIGuardIdleState::singletonInstance(guard);
}
