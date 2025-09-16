// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NinjaCombatGameMode.h"

#include "MyProjectGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AMyProjectGameMode : public ANinjaCombatGameMode
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AMyProjectGameMode();
};



