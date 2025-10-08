// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/NinjaFactionPlayerController.h"
#include "MyProjectPlayerController.generated.h"

class UNinjaInputManagerComponent;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class AMyProjectPlayerController : public ANinjaFactionPlayerController
{
	GENERATED_BODY()

public:
	AMyProjectPlayerController();
private:

	/** Manages player input, using Enhanced Input/Ninja Input. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Components, meta=(AllowPrivateAccess=true))
	TObjectPtr<UNinjaInputManagerComponent> InputManager;

};
