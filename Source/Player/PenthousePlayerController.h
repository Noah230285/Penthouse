// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PenthousePlayerController.generated.h"

class UInputMappingContext;

UENUM(BlueprintType, Flags, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EPlayerFreezeFlags : uint8
{
	NONE = 0,
	OBJECT_EXAMINE = 0x01,
	GAME_PAUSE = 0x02,
	CUTSCENE = 0x04,
};
ENUM_CLASS_FLAGS(EPlayerFreezeFlags);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerFrozenSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerUnFrozenSignature);

UCLASS()
class PENTHOUSE_API APenthousePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPlayerFrozenSignature OnPlayerFrozen;
	UPROPERTY(BlueprintAssignable)
	FOnPlayerUnFrozenSignature OnPlayerUnFrozen;
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Input)
	uint8 FreezeFlags;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ApplyFreezeFlags(const uint8 Flags);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ClearFreezeFlags(const uint8 Flags);
	UFUNCTION(BlueprintCallable)
	bool CanPlayerMove() const;
	
protected:

	virtual void BeginPlay() override;
};
