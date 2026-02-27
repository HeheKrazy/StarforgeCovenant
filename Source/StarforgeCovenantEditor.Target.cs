// Copyright HeheKrazy

using UnrealBuildTool;
using System.Collections.Generic;

public class StarforgeCovenantEditorTarget : TargetRules
{
	public StarforgeCovenantEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "StarforgeCovenant" } );
	}
}
