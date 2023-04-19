// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RequestHUD.generated.h"

/**
 * 
 */
UCLASS()
class BAEKYA_API URequestHUD : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(meta = (BindWidget))
	class UScrollBox* RequestScrollBox;
public:
	UScrollBox* GetScrollBox();
};
