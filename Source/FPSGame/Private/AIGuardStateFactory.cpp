// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardStateFactory.h"
#include "AIGuardIdleState.h"
#include "AIGuardSuspiciousState.h"
#include "AIGuardAlertedState.h"

AIGuardStateFactory::AIGuardStateFactory(AFPSAIGuard* guard)
{
	state = AIGuardIdleState::singletonInstance(guard);
}

AIGuardState* AIGuardStateFactory::reactToNoise(AFPSAIGuard* guard)
{
	state = state->reactToNoise(guard);
	return state;
}

AIGuardState* AIGuardStateFactory::reactToSpotting(AFPSAIGuard* guard)
{
	state = state->reactToSpotting(guard);
	return state;
}

AIGuardState* AIGuardStateFactory::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	state = state->goingBackToOriginalPosition(guard);
	return state;
}

