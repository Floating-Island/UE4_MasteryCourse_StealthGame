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
	return state->reactToNoise();
}

AIGuardState* AIGuardStateFactory::reactToSpotting()
{
	return state->reactToSpotting();
}

AIGuardState* AIGuardStateFactory::goingBackToOriginalPosition(AFPSAIGuard* guard)
{
	return state->goingBackToOriginalPosition(guard);
}

