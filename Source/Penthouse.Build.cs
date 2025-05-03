// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Penthouse : ModuleRules
{
	public Penthouse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
		PublicIncludePaths.AddRange(new string[] { "Interaction", "Player", "Utility", "Source/Interaction" });
	}
}
