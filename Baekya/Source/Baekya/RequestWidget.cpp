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
