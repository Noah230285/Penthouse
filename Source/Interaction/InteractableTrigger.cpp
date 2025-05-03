// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableTrigger.h"

// Sets default values for this component's properties
AInteractableTrigger::AInteractableTrigger()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	SphereCollider->SetRelativeLocation(FVector(0, 0, 0));
	SphereCollider->SetCollisionProfileName("Interactable");
	SphereCollider->SetSphereRadius(InteractableRadius);

	InteractObject = CreateDefaultSubobject<UChildActorComponent>(TEXT("Interact Object"));
	InteractObject->SetupAttachment(SphereCollider);
	InteractObject->SetRelativeLocation(FVector(0, 0, 0));
}


// Called when the game starts
void AInteractableTrigger::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void AInteractableTrigger::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}

void AInteractableTrigger::OnInteracted(ACharacter* Interactor)
{
	OnInteractedDelegate.Broadcast(Interactor);
}

