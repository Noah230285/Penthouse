// Fill out your copyright notice in the Description page of Project Settings.


#include "PenthouseHUD.h"

const TArray<AInteractableTrigger*> APenthouseHUD::GetLoadedSimpleInteractors_Implementation() const
{
	return LoadedInteractors;
}

bool APenthouseHUD::AddSimpleInteractor_Implementation(AInteractableTrigger* Trigger)
{
	if (LoadedInteractors.Contains(Trigger))
	{
		return false;
	}
	LoadedInteractors.Add(Trigger);
	return true;
}

bool APenthouseHUD::RemoveSimpleInteractor_Implementation(AInteractableTrigger* Trigger)
{
	if (!LoadedInteractors.Contains(Trigger))
	{
		return false;
	}
	LoadedInteractors.Remove(Trigger);
	return true;
}
