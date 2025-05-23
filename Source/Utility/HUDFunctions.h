﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HUDFunctions.generated.h"

class AInteractableTrigger;
// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UHUDFunctions : public UInterface
{
	GENERATED_BODY()
};


class PENTHOUSE_API IHUDFunctions
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	const TArray<AInteractableTrigger*> GetLoadedSimpleInteractors() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool RemoveSimpleInteractor(AInteractableTrigger* Trigger);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool AddSimpleInteractor(AInteractableTrigger* Trigger);
};
