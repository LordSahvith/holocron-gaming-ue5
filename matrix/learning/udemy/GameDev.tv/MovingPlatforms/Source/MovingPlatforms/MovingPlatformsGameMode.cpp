// Copyright Epic Games, Inc. All Rights Reserved.

#include "MovingPlatformsGameMode.h"
#include "MovingPlatformsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMovingPlatformsGameMode::AMovingPlatformsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
