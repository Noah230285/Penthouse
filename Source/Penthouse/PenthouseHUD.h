// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUDFunctions.h"
#include "InteractableTrigger.h"
#include "GameFramework/HUD.h"
#include "PenthouseHUD.generated.h"

/**
 * 
 */
UCLASS()
class PENTHOUSE_API APenthouseHUD : public AHUD, public IHUDFunctions
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	 TArray<AUInteractableTrigger*> LoadedInteractors = {};


public:
	
	const TArray<AUInteractableTrigger*> GetLoadedSimpleInteractors_Implementation() const override;

	virtual bool AddSimpleInteractor_Implementation(AUInteractableTrigger* Trigger) override;
	
	virtual bool RemoveSimpleInteractor_Implementation(AUInteractableTrigger* Trigger) override;

};
