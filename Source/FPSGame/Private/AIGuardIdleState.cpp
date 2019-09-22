// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardIdleState.h"
#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"

AIGuardIdleState::AIGuardIdleState()
{
}

AIGuardState* AIGuardIdleState::singletonInstance()
{
	static AIGuardIdleState initializedInstance;
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

AIGuardState* AIGuardIdleState::goingBackToOriginalPosition()
{
	return this;
}
