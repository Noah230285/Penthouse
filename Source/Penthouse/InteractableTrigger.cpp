// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableTrigger.h"

// Sets default values for this component's properties
AUInteractableTrigger::AUInteractableTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SphereCollider->SetRelativeLocation(FVector(0, 0, 0));
}


// Called when the game starts
void AUInteractableTrigger::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void AUInteractableTrigger::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}

void AUInteractableTrigger::OnInteracted()
{
	OnInteractedDelegate.Broadcast();
}

