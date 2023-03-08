// Copyright Epic Games, Inc. All Rights Reserved.

#include "BaekyaGameMode.h"
#include "BaekyaCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABaekyaGameMode::ABaekyaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
