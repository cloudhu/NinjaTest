// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyProject : ModuleRules
{
	public MyProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange([
			"Core",
			"CoreOnline",
			"CoreUObject",
			"ApplicationCore",
			"Engine",
			"PhysicsCore",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			//Ninja Foundation
			"NinjaGAS",
			"NinjaInput",
			// Ninja Combat
			"CommonUI",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"ModelViewViewModel",
			"NinjaCombat",
			"NinjaCombatCamera",
			"NinjaCombatCore",
			"NinjaCombatActorPool",
			"NinjaCombatUI",
			"NinjaCombatInventory",
			"StructUtils",
			"NinjaCombatFactions",
			"TargetingSystem",
			// Ninja Inventory
			"NinjaInventory",
			"NinjaInventoryCore",
			"NinjaInventoryEquipment",
			"CommonInput",
			"NinjaFactions",
			"DataRegistry",
			"GameFeatures",			
			"PropertyPath",
			//Ninja Interaction
			"NinjaInteraction",
			"NinjaInteractionUI",
			"SmartObjectsModule"

		]);

		PrivateDependencyModuleNames.AddRange([
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"NinjaGAS",
			"NinjaCombat",
			"NinjaFactions",
			"NinjaCombatFactions",
			"NinjaInventoryEquipment",
			"NinjaInput"
		]);

		PublicIncludePaths.AddRange([
			"MyProject",
			"MyProject/Variant_Platforming",
			"MyProject/Variant_Platforming/Animation",
			"MyProject/Variant_Combat",
			"MyProject/Variant_Combat/AI",
			"MyProject/Variant_Combat/Animation",
			"MyProject/Variant_Combat/Gameplay",
			"MyProject/Variant_Combat/Interfaces",
			"MyProject/Variant_Combat/UI",
			"MyProject/Variant_SideScrolling",
			"MyProject/Variant_SideScrolling/AI",
			"MyProject/Variant_SideScrolling/Gameplay",
			"MyProject/Variant_SideScrolling/Interfaces",
			"MyProject/Variant_SideScrolling/UI"
		]);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}