// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyProjectPlayerController.h"

#include "Components/NinjaInputManagerComponent.h"

AMyProjectPlayerController::AMyProjectPlayerController()
{
	static const FName InputManagerName = FName("InputManager");
	InputManager = CreateDefaultSubobject<UNinjaInputManagerComponent>(InputManagerName);
}
