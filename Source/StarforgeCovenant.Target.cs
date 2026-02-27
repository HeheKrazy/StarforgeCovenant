// Copyright HeheKrazy

using UnrealBuildTool;
using System.Collections.Generic;

public class StarforgeCovenantTarget : TargetRules
{
	public StarforgeCovenantTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "StarforgeCovenant" } );
	}
}
