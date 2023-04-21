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

	// WBP_Request ������
	// �����ķ� ������µ� ��ȿ�����ε�? �ٸ� ����� �𸣰ھ
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

	// ���� ġ��������� �����ؼ� �� �ֱ�
	void SetRequestBody(FString Body);
};
