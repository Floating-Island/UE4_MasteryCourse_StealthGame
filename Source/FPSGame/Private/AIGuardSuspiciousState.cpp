// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"
#include "AIGuardIdleState.h"
#include "FPSAIGuard.h"
#include "UAIGuardState.h"

AIGuardSuspiciousState::AIGuardSuspiciousState()
{
}

AIGuardState* AIGuardSuspiciousState::singletonInstance()
{
	static AIGuardSuspiciousState initializedInstance;
	UUAIGuardState::onSuspiciousStateEvent();
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
