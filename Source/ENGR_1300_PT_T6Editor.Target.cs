// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ENGR_1300_PT_T6EditorTarget : TargetRules
{
	public ENGR_1300_PT_T6EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;

		ExtraModuleNames.AddRange( new string[] { "ENGR_1300_PT_T6" } );
	}
}
