// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Study_FPS_201223 : ModuleRules
{
	public Study_FPS_201223(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
