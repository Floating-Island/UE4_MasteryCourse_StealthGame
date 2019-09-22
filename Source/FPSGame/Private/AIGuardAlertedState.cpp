// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardAlertedState.h"

AIGuardAlertedState::AIGuardAlertedState()
{
}

AIGuardState* AIGuardAlertedState::singletonInstance()
{
	static AIGuardAlertedState initializedInstance;
	AIGuardAlertedState::onAlertedStateEvent();
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
