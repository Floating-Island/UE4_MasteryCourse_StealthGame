// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardStateFactory.h"
#include "AIGuardIdleState.h"
#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"

AIGuardStateFactory::AIGuardStateFactory()
{
	state = AIGuardIdleState::singletonInstance();
}

AIGuardState* AIGuardStateFactory::reactToNoise()
{
	state = state->reactToNoise();
	return state;
}

AIGuardState* AIGuardStateFactory::reactToSpotting()
{
	state = state->reactToSpotting();
	return state;
}

AIGuardState* AIGuardStateFactory::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	state = state->goingBackToOriginalPosition(guard);
	return state;
}

