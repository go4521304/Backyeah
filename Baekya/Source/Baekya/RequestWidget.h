// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "RequestWidget.generated.h"

/**
 * 
 */

UCLASS()
class BAEKYA_API URequestWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* RequestSwitcher;
public:
	UWidgetSwitcher* GetRequestSwitcher();
	UFUNCTION(BlueprintCallable)
	void SetRequestSwitcherIndex(int32 Index);
};
