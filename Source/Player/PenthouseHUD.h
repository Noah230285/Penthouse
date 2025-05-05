// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Utility/HUDFunctions.h"
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
	 TArray<AInteractableTrigger*> LoadedInteractors = {};


public:
	
	const TArray<AInteractableTrigger*> GetLoadedSimpleInteractors_Implementation() const override;

	virtual bool AddSimpleInteractor_Implementation(AInteractableTrigger* Trigger) override;
	
	virtual bool RemoveSimpleInteractor_Implementation(AInteractableTrigger* Trigger) override;

};
