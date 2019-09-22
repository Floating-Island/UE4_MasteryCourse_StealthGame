// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardIdleState.h"
#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"
#include "FPSAIGuard.h"

AIGuardIdleState::AIGuardIdleState()
{
}

AIGuardState* AIGuardIdleState::singletonInstance(AFPSAIGuard* guard)
{
	static AIGuardIdleState initializedInstance;
	guard->onIdleStateEvent();;
	return &initializedInstance;
}

AIGuardState* AIGuardIdleState::reactToNoise(AFPSAIGuard* guard)
{
	return AIGuardSuspiciousState::singletonInstance(guard);
}

AIGuardState* AIGuardIdleState::reactToSpotting(AFPSAIGuard* guard)
{
	return AIGuardAlertedState::singletonInstance(guard);
}

AIGuardState* AIGuardIdleState::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	guard->initialOrientation();
	return this;
}
