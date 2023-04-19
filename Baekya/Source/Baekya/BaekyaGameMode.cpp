// Copyright Epic Games, Inc. All Rights Reserved.

#include "BaekyaGameMode.h"
#include "BaekyaCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "RequestHUD.h"
#include "RequestWidget.h"
#include "Components/ScrollBox.h"

ABaekyaGameMode::ABaekyaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<URequestHUD> RequestHUD(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/ThirdPerson/Blueprints/WBP_RequestHUD.WBP_RequestHUD_C'"));
	static ConstructorHelpers::FClassFinder<URequestWidget> RequestWidget(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/ThirdPerson/Blueprints/WBP_Request.WBP_Request'"));
	if (RequestHUD.Succeeded())
	{
		HUD_Class = RequestHUD.Class;
		RequestWidget_Class = RequestWidget.Class;

		CurrentWidget = Cast<URequestHUD>(CreateWidget(GetWorld(), HUD_Class));
		
		if(CurrentWidget)
		{
			for (int i = 0; i < 20; ++i) 
			{
				URequestWidget* CurrentRequestWidget;
				CurrentRequestWidget = Cast<URequestWidget>(CreateWidget(GetWorld(), RequestWidget_Class));
				FMargin Margin;
				Margin.Right = 25.f;
				Margin.Left = 25.f;
				Margin.Top = 25.f;
				Margin.Bottom = 0.f;
				CurrentRequestWidget->Padding.Right = Margin.Right;
				CurrentRequestWidget->Padding.Left = Margin.Left;
				CurrentRequestWidget->Padding.Top = Margin.Top;
				CurrentRequestWidget->Padding.Bottom = Margin.Bottom;
				CurrentWidget->GetScrollBox()->AddChild(CurrentRequestWidget);
			}
			CurrentWidget->AddToViewport();
			//CurrentWidget->RemoveFromViewport();
		}
	}
}
