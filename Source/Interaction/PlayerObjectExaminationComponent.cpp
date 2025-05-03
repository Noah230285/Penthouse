// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerObjectExaminationComponent.h"

#include "Components/SceneCaptureComponent2D.h"
#include "Engine/World.h"
#include "Interaction/ExaminableObjectActor.h"

// Sets default values for this component's properties
UPlayerObjectExaminationComponent::UPlayerObjectExaminationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene Capture"));
	SceneCapture->SetRelativeLocation(FVector(0, 0.f, 0)); // Position the camera
}


// Called when the game starts
void UPlayerObjectExaminationComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UPlayerObjectExaminationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerObjectExaminationComponent::EnterExamineState_Implementation(
	TSubclassOf<AExaminableObjectActor> ActorClass)
{
	
}

void UPlayerObjectExaminationComponent::ExitExamineState_Implementation()
{
	
}



void UPlayerObjectExaminationComponent::AddExamineActor_Implementation(TSubclassOf<AExaminableObjectActor> ActorClass)
{
	ExaminedActor = StaticCast<AExaminableObjectActor*>(GetWorld()->SpawnActor(ActorClass));
	ExaminedActor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepRelativeTransform, "None");
	ExaminedActor->SetActorRelativeLocation(ExaminedActor->GetExaminationPositionOffset());
}

void UPlayerObjectExaminationComponent::RemoveExamineActor_Implementation()
{
	ExaminedActor->Destroy();
}
