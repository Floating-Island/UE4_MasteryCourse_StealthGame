// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardAlertedState.h"

AIGuardAlertedState::AIGuardAlertedState()
{
}

AIGuardState* AIGuardAlertedState::singletonInstance()
{
	static AIGuardAlertedState initializedInstance;
	return &initializedInstance;
}

AIGuardState* AIGuardAlertedState::reactToNoise()
{
	return AIGuardAlertedState::singletonInstance();
}

AIGuardState* AIGuardAlertedState::reactToSpotting()
{
	return AIGuardAlertedState::singletonInstance();
}

AIGuardState* AIGuardAlertedState::goingBackToOriginalPosition()
{
	return AIGuardAlertedState::singletonInstance();
}
