// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "PlayerObjectExaminationComponent.generated.h"


class AExaminableObjectActor;

UCLASS(Blueprintable, ClassGroup=(Custom))
class PENTHOUSE_API UPlayerObjectExaminationComponent : public USceneCaptureComponent2D
{
	GENERATED_BODY()

protected:	
	/** Scene capture used for object examination */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UChildActorComponent* ExamineChildActor;

public:
	/** Scene capture used for object examination */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AExaminableObjectActor* ExaminedActor;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void OnRegister() override;

public:
	// Sets default values for this component's properties
	UPlayerObjectExaminationComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void EnterExamineState(TSubclassOf<AExaminableObjectActor> ActorClass);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ExitExamineState();
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void AddExamineActor(TSubclassOf<AExaminableObjectActor> ActorClass);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RemoveExamineActor();

	
};
