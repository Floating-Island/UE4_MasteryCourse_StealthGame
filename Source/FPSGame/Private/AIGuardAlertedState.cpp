// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardAlertedState.h"
#include "UAIGuardState.h"

AIGuardAlertedState::AIGuardAlertedState()
{
}

AIGuardState* AIGuardAlertedState::singletonInstance()
{
	static AIGuardAlertedState initializedInstance;
	UUAIGuardState::onAlertedStateEvent();
	return &initializedInstance;
}

AIGuardState* AIGuardAlertedState::reactToNoise()
{
	return this;
}

AIGuardState* AIGuardAlertedState::reactToSpotting()
{
	return this;
}

AIGuardState* AIGuardAlertedState::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	return this;
}
