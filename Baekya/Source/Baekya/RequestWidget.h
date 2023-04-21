// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "Components/MultiLineEditableTextBox.h"
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

	// WBP_Request 검토좀
	// 스위쳐로 만들었는데 비효울적인듯? 다른 방법은 모르겠어서
	UPROPERTY(meta = (BindWidget))
	UTextBlock* RequestTitleText1;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RequestTitleText2;

	UPROPERTY(meta = (BindWidget))
	UMultiLineEditableTextBox* RequestBody;

public:
	UWidgetSwitcher* GetRequestSwitcher();
	UFUNCTION(BlueprintCallable)
	void SetRequestSwitcherIndex(int32 Index);

	void SetRequestTitleText(FString Title);

	// 엔터 치고싶은데에 구분해서 잘 넣기
	void SetRequestBody(FString Body);
};
