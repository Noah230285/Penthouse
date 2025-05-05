// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "ExaminableObjectActor.generated.h"


UCLASS(Blueprintable, Abstract, ClassGroup=(Custom))
class PENTHOUSE_API AExaminableObjectActor : public AActor
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector ExaminationPositionOffset;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Sets default values for this component's properties
	AExaminableObjectActor();

	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	FVector3d GetExaminationPositionOffset() const {return ExaminationPositionOffset;};
};