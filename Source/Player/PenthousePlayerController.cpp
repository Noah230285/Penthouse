// Copyright Epic Games, Inc. All Rights Reserved.


#include "PenthousePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void APenthousePlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void APenthousePlayerController::ApplyFreezeFlags_Implementation(const uint8 Flags)
{
	FreezeFlags |= Flags;
	if (!CanPlayerMove())
	{
		OnPlayerFrozen.Broadcast();
	}
}

void APenthousePlayerController::ClearFreezeFlags_Implementation(const uint8 Flags)
{
	FreezeFlags &= ~Flags;
	if (CanPlayerMove())
	{
		OnPlayerUnFrozen.Broadcast();
	}
}

bool APenthousePlayerController::CanPlayerMove() const
{
	return FreezeFlags == 0;
}
