// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardIdleState.h"
#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"
#include "FPSAIGuard.h"

AIGuardIdleState::AIGuardIdleState()
{
}

AIGuardState* AIGuardIdleState::singletonInstance()
{
	static AIGuardIdleState initializedInstance;
	AIGuardIdleState::onIdleStateEvent();
	return &initializedInstance;
}

AIGuardState* AIGuardIdleState::reactToNoise()
{
	return AIGuardSuspiciousState::singletonInstance();
}

AIGuardState* AIGuardIdleState::reactToSpotting()
{
	return AIGuardAlertedState::singletonInstance();
}

AIGuardState* AIGuardIdleState::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	guard->initialOrientation();
	return this;
}
