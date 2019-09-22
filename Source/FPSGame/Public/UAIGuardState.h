// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UAIGuardState.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UUAIGuardState : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void static onIdleStateEvent();
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void static onSuspiciousStateEvent();
	UFUNCTION(BlueprintImplementableEvent, Category = "AI Guard State")
		void static onAlertedStateEvent();
};
