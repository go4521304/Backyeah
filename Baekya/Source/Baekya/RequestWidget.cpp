// Fill out your copyright notice in the Description page of Project Settings.


#include "RequestWidget.h"

UWidgetSwitcher* URequestWidget::GetRequestSwitcher()
{
	return RequestSwitcher;
}

void URequestWidget::SetRequestSwitcherIndex(int32 Index)
{
	if (RequestSwitcher->GetActiveWidgetIndex() != Index)
		RequestSwitcher->SetActiveWidgetIndex(Index);
}

void URequestWidget::SetRequestTitleText(FString Title)
{
	FText FTextTitle = FText::FromString(Title);
	RequestTitleText1->SetText(FTextTitle);
	RequestTitleText2->SetText(FTextTitle);
}

void URequestWidget::SetRequestBody(FString Body)
{
	FText FTextBody = FText::FromString(Body);
	RequestBody->SetText(FTextBody);
}
