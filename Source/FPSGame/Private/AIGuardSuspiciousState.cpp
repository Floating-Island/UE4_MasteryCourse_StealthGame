// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardSuspiciousState.h"

AIGuardSuspiciousState::AIGuardSuspiciousState()
{
}

AIGuardState* AIGuardSuspiciousState::singletonInstance()
{
	static AIGuardSuspiciousState initializedInstance;
	return &initializedInstance;
}
