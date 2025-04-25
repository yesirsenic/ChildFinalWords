// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ChildFinalWords : ModuleRules
{
	public ChildFinalWords(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
