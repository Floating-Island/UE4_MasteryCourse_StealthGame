// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardAlertedState.h"
#include "FPSAIGuard.h"

AIGuardAlertedState::AIGuardAlertedState()
{
}

AIGuardState* AIGuardAlertedState::singletonInstance(AFPSAIGuard* guard)
{
	static AIGuardAlertedState initializedInstance;
	guard->alertedState();
	return &initializedInstance;
}

AIGuardState* AIGuardAlertedState::reactToNoise(AFPSAIGuard* guard)
{
	return this;
}

AIGuardState* AIGuardAlertedState::reactToSpotting(AFPSAIGuard* guard)
{
	return this;
}

AIGuardState* AIGuardAlertedState::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	return this;
}
