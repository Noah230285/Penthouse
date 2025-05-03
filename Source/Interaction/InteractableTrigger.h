// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Player/PenthouseCharacter.h"
#include "InteractableTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractedSignature, ACharacter*, InteractPawn);

UCLASS(Blueprintable, Abstract, ClassGroup=(Custom))
class PENTHOUSE_API AInteractableTrigger : public AActor
{
	GENERATED_BODY()

public:	
	UPROPERTY(BlueprintAssignable)
	FOnInteractedSignature OnInteractedDelegate;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* SphereCollider;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UChildActorComponent* InteractObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InteractableRadius = 10;

	
public:
	AInteractableTrigger();

	// Called every frame
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void OnInteracted(ACharacter* Interactor);

protected:
	
	// Called when the game starts
	virtual void BeginPlay() override;


};
