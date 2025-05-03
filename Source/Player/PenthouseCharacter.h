// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "PenthouseCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class APenthouseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* FirstPersonCameraComponent;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bBlockMovement;

protected:
		
public:
	APenthouseCharacter();

    USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	
    UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
    
protected:
	virtual void BeginPlay();

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);
	
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
};

