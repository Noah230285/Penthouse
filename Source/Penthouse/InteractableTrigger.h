// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "InteractableTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractedSignature);

UCLASS(Blueprintable, Abstract, ClassGroup=(Custom))
class PENTHOUSE_API AUInteractableTrigger : public AActor
{
	GENERATED_BODY()

public:	
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USphereComponent* SphereCollider;

public:	
	// Sets default values for this component's properties
	AUInteractableTrigger();

	UPROPERTY(BlueprintAssignable)
	FOnInteractedSignature OnInteractedDelegate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	virtual void OnInteracted();

};
