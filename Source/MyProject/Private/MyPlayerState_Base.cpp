// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/MyPlayerState_Base.h"

#include "Components/NinjaInventoryManagerComponent.h"

AMyPlayerState_Base::AMyPlayerState_Base(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	InventoryManager = CreateDefaultSubobject<UNinjaInventoryManagerComponent>(TEXT("InventoryManager"));
}

UNinjaInventoryManagerComponent* AMyPlayerState_Base::GetInventoryManager_Implementation() const
{
	return InventoryManager;
}
