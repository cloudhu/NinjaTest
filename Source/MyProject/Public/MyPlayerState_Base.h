// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NinjaGASPlayerState.h"

#include "Interfaces/InventorySystemInterface.h"

#include "MyPlayerState_Base.generated.h"

class UNinjaInventoryManagerComponent;
/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerState_Base : public ANinjaGASPlayerState, public IInventorySystemInterface
{
	GENERATED_BODY()

public:
	AMyPlayerState_Base(const FObjectInitializer& ObjectInitializer);

	// -- Begin InventorySystem implementation
	virtual UNinjaInventoryManagerComponent* GetInventoryManager_Implementation() const override;
	// -- End InventorySystem implementation
	
private:

	/** Inventory Manager component. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNinjaInventoryManagerComponent> InventoryManager;
};
