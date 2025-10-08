// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NinjaGASPlayerCharacter.h"

#include "Interfaces/CombatSystemInterface.h"
#include "Interfaces/EquipmentSystemInterface.h"
#include "Interfaces/FactionMemberInterface.h"
#include "Interfaces/InputSetupProviderInterface.h"

#include "Logging/LogMacros.h"
#include "MyProjectCharacter.generated.h"

class UNinjaInputSetupDataAsset;
class UNinjaCombatMotionWarpingComponent;
class UNinjaInteractionManagerComponent;
class UNinjaCombatComboManagerComponent;
class UNinjaFactionComponent;
class UNinjaCombatEquipmentAdapterComponent;
class UNinjaEquipmentManagerComponent;
class UNinjaCombatManagerComponent;
class USpringArmComponent;
class UCameraComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class AMyProjectCharacter : public ANinjaGASPlayerCharacter, public ICombatSystemInterface, public IInputSetupProviderInterface,
												public IEquipmentSystemInterface, public IFactionMemberInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** Combat Manager component. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaCombatManagerComponent> CombatManager;

	/** Forward Reference (Input and Combat integration). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UArrowComponent> ForwardReference;

	/** Equipment Manager component. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaEquipmentManagerComponent> EquipmentManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaCombatEquipmentAdapterComponent> EquipmentWeaponManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UNinjaFactionComponent> FactionManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaCombatComboManagerComponent> ComboManager;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UNinjaInteractionManagerComponent > InteractionComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UNinjaCombatMotionWarpingComponent > MotionWarpingComponent;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input Setup")
	TArray<UNinjaInputSetupDataAsset*> CharacterInputs;
	
public:

	/** Constructor */
	AMyProjectCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());


	// -- Begin CombatSystem implementation
	virtual UNinjaCombatManagerComponent* GetCombatManager_Implementation() const override;
	virtual USceneComponent* GetCombatForwardReference_Implementation() const override;
	virtual USkeletalMeshComponent* GetCombatMesh_Implementation() const override;
	virtual UAnimInstance* GetCombatAnimInstance_Implementation() const override;
	virtual UActorComponent* GetWeaponManagerComponent_Implementation() const override;
	virtual UActorComponent* GetComboManagerComponent_Implementation() const override;
	virtual UActorComponent* GetMotionWarpingComponent_Implementation() const override;
	// -- End CombatSystem implementation

	// -- Begin Input Setup Provider implementation
	virtual TArray<UNinjaInputSetupDataAsset*> GetInputSetups_Implementation() const override;
	// -- End Input Setup Provider implementation

	// -- Begin EquipmentSystem implementation
	virtual UNinjaEquipmentManagerComponent* GetEquipmentManager_Implementation() const override;
	// -- End EquipmentSystem implementation

	// -- Begin Faction Member implementation
	virtual UNinjaFactionComponent* GetFactionComponent_Implementation() const override;
	// -- End Faction Member implementation
	
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }


	
};

