// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerObjectExaminationActor.h"

#include "Components/SceneCaptureComponent2D.h"
#include "Engine/World.h"
#include "Interaction/ExaminableObjectActor.h"

// Sets default values for this component's properties
APlayerObjectExaminationActor::APlayerObjectExaminationActor()
{
	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Scene Capture"));
	
	ExamineChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("Examine Child Actor"));
	ExamineChildActor->SetupAttachment(SceneCapture);
	ExamineChildActor->SetRelativeLocation(FVector(100, 0, 0));
}


// Called when the game starts
void APlayerObjectExaminationActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerObjectExaminationActor::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}

void APlayerObjectExaminationActor::EnterExamineState_Implementation(
	TSubclassOf<AExaminableObjectActor> ActorClass)
{
	AddExamineActor(ActorClass);
}

void APlayerObjectExaminationActor::ExitExamineState_Implementation()
{
	
}

void APlayerObjectExaminationActor::AddExamineActor_Implementation(TSubclassOf<AExaminableObjectActor> ActorClass)
{
	ExamineChildActor->SetChildActorClass(ActorClass);
	ExaminedActor = StaticCast<AExaminableObjectActor*>(ExamineChildActor->GetChildActor());
	for (auto Component : ExaminedActor->GetComponents())
	{
		if (UMeshComponent* Mesh = Cast<UMeshComponent>(Component))
		{
			Mesh->SetVisibleInSceneCaptureOnly(true);
		}
	}
	SceneCapture->ShowOnlyActors.Add(ExaminedActor);
	
	ExamineChildActor->SetRelativeLocation(ExaminedActor->GetExaminationPositionOffset());
	ExamineChildActor->SetRelativeRotation(ExaminedActor->GetExaminationRotationOffset());
}

void APlayerObjectExaminationActor::RemoveExamineActor_Implementation()
{
	ExaminedActor->Destroy();
}
