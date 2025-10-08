// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectCharacter.h"
#include "Components/NinjaCombatManagerComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "NinjaCombatTags.h"
#include "Components/ArrowComponent.h"
#include "Components/NinjaCombatCharacterMovementComponent.h"
#include "Components/NinjaCombatComboManagerComponent.h"
#include "Components/NinjaCombatMotionWarpingComponent.h"
#include "Components/NinjaFactionComponent.h"
#include "Components/NinjaInteractionManagerComponent.h"

#include "NinjaCombatInventory/Public/Components/NinjaCombatEquipmentAdapterComponent.h"

#include "NinjaInventoryEquipment/Public/Components/NinjaEquipmentManagerComponent.h"

AMyProjectCharacter::AMyProjectCharacter(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer.SetDefaultSubobjectClass<UNinjaCombatCharacterMovementComponent>(CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	CombatManager = CreateDefaultSubobject<UNinjaCombatManagerComponent>("CombatManager");
	ComboManager = CreateDefaultSubobject<UNinjaCombatComboManagerComponent>("ComboManager");
	InteractionComponent = CreateDefaultSubobject<UNinjaInteractionManagerComponent >("InteractionComponent");
	MotionWarpingComponent = CreateDefaultSubobject<UNinjaCombatMotionWarpingComponent >("MotionWarpingComponent");

	ForwardReference = CreateDefaultSubobject<UArrowComponent>("ForwardReference");
	ForwardReference->ComponentTags.Add(Tag_Combat_Component_ForwardReference.GetTag().GetTagName());
	ForwardReference->SetVisibleFlag(false);
	ForwardReference->SetUsingAbsoluteRotation(true);
	ForwardReference->SetWorldRotation(FRotator::ZeroRotator);
	ForwardReference->SetArrowColor(FLinearColor::Green);
	ForwardReference->SetupAttachment(GetRootComponent());

	/** Equipment Manager component. */
	EquipmentManager = CreateDefaultSubobject<UNinjaEquipmentManagerComponent>(TEXT("EquipmentManager"));
	EquipmentWeaponManager = CreateDefaultSubobject<UNinjaCombatEquipmentAdapterComponent>(TEXT("EquipmentWeaponManager"));

	static const FName FactionComponentName = TEXT("FactionManager");
	FactionManager = CreateOptionalDefaultSubobject<UNinjaFactionComponent>(FactionComponentName);
}

UNinjaCombatManagerComponent* AMyProjectCharacter::GetCombatManager_Implementation() const
{
	return CombatManager;
}

USceneComponent* AMyProjectCharacter::GetCombatForwardReference_Implementation() const
{
	return ForwardReference;
}

USkeletalMeshComponent* AMyProjectCharacter::GetCombatMesh_Implementation() const
{
	return GetMesh();
}

UAnimInstance* AMyProjectCharacter::GetCombatAnimInstance_Implementation() const
{
	return GetMesh()->GetAnimInstance();
}

UActorComponent* AMyProjectCharacter::GetWeaponManagerComponent_Implementation() const
{
	return EquipmentWeaponManager;
}

UActorComponent* AMyProjectCharacter::GetComboManagerComponent_Implementation() const
{
	return ComboManager;
}

UActorComponent* AMyProjectCharacter::GetMotionWarpingComponent_Implementation() const
{
	return MotionWarpingComponent;
}

TArray<UNinjaInputSetupDataAsset*> AMyProjectCharacter::GetInputSetups_Implementation() const
{
	return CharacterInputs;
}

UNinjaEquipmentManagerComponent* AMyProjectCharacter::GetEquipmentManager_Implementation() const
{
	return EquipmentManager;
}

UNinjaFactionComponent* AMyProjectCharacter::GetFactionComponent_Implementation() const
{
	return FactionManager;
}

