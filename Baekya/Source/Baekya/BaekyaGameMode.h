// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RequestHUD.h"
#include "RequestWidget.h"
#include "BaekyaGameMode.generated.h"

UCLASS(minimalapi)
class ABaekyaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABaekyaGameMode();

	TSubclassOf<UUserWidget>HUD_Class;
	TSubclassOf<UUserWidget>RequestWidget_Class;
	URequestHUD* CurrentWidget;
};