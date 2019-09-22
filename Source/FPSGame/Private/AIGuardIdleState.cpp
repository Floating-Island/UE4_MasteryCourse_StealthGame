// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuardIdleState.h"

AIGuardIdleState::AIGuardIdleState()
{
}

AIGuardState* AIGuardIdleState::singletonInstance()
{
	static AIGuardIdleState initializedInstance;
	return &initializedInstance;
}