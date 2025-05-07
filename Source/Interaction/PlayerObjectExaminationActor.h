#pragma once
 
 #include "CoreMinimal.h"
 #include "Components/ActorComponent.h"
 #include "PlayerObjectExaminationActor.generated.h"
 
 
 class AExaminableObjectActor;
 
 UCLASS(Blueprintable, ClassGroup=(Custom))
 class PENTHOUSE_API APlayerObjectExaminationActor : public AActor
 {
 	GENERATED_BODY()
 
 protected:	
 	/** Scene capture used for object examination */
 	UPROPERTY(EditAnywhere, BlueprintReadWrite)
 	USceneCaptureComponent2D* SceneCapture;

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
 
 public:
 	// Sets default values for this component's properties
 	APlayerObjectExaminationActor();
 	
 	// Called every frame
	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;
 	
 	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
 	void EnterExamineState(TSubclassOf<AExaminableObjectActor> ActorClass);
 	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
 	void ExitExamineState();
 	
 	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
 	void AddExamineActor(TSubclassOf<AExaminableObjectActor> ActorClass);
 	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
 	void RemoveExamineActor();
 
 	
 };