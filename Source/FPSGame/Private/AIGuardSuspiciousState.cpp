// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"
#include "AIGuardIdleState.h"

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
	return AIGuardSuspiciousState::singletonInstance();
}

AIGuardState* AIGuardSuspiciousState::reactToSpotting()
{
	return AIGuardAlertedState::singletonInstance();
}

AIGuardState* AIGuardSuspiciousState::goingBackToOriginalPosition()
{
	return AIGuardIdleState::singletonInstance();
}
