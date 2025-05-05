// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerObjectExaminationComponent.h"

#include "Components/SceneCaptureComponent2D.h"
#include "Engine/World.h"
#include "Interaction/ExaminableObjectActor.h"

// Sets default values for this component's properties
UPlayerObjectExaminationComponent::UPlayerObjectExaminationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	ExamineChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("Examine Child Actor"));

}


// Called when the game starts
void UPlayerObjectExaminationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerObjectExaminationComponent::OnRegister()
{
	Super::OnRegister();

	ExamineChildActor->SetupAttachment(this);
	ExamineChildActor->SetRelativeLocation(FVector(0, 100, 0));
}


// Called every frame
void UPlayerObjectExaminationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerObjectExaminationComponent::EnterExamineState_Implementation(
	TSubclassOf<AExaminableObjectActor> ActorClass)
{
	AddExamineActor(ActorClass);
}

void UPlayerObjectExaminationComponent::ExitExamineState_Implementation()
{
	
}

void UPlayerObjectExaminationComponent::AddExamineActor_Implementation(TSubclassOf<AExaminableObjectActor> ActorClass)
{
	ExamineChildActor->SetChildActorClass(ActorClass);
	ExaminedActor = StaticCast<AExaminableObjectActor*>(ExamineChildActor->GetChildActor());
	// for (auto Component : ExaminedActor->GetComponents())
	// {
	// 	if (USceneComponent* SceneComponent = Cast<USceneComponent>(Component))
	// 	{
	// 		SceneComponent->SetVisibility(false);
	// 	}
	// }
	//
	// ExamineChildActor->SetRelativeLocation(ExaminedActor->GetExaminationPositionOffset());
	// ExamineChildActor->SetRelativeRotation(ExaminedActor->GetExaminationStartRotation());
}

void UPlayerObjectExaminationComponent::RemoveExamineActor_Implementation()
{
	ExaminedActor->Destroy();
}
