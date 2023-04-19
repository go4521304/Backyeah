// Fill out your copyright notice in the Description page of Project Settings.

#include "RequestGameInstance.h"

URequestGameInstance::URequestGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("/Script/Engine.DataTable'/Game/Data/RequestData.RequestData'"));

	QuestTable = DATA.Object;
}

FREQUEST* URequestGameInstance::GetReq(int32 idx)
{
	return QuestTable->FindRow<FREQUEST>(*FString::FromInt(idx), TEXT(""));;
}

FString URequestGameInstance::GetReqTitle(int32 idx)
{
	return GetReq(idx)->Title;
}

FString URequestGameInstance::GetReqBody(int32 idx)
{
	return GetReq(idx)->Body;
}

int32 URequestGameInstance::GetReqTime(int32 idx)
{
	return GetReq(idx)->Time;
}

FString URequestGameInstance::GetReqStory(int32 idx)
{
	return FString();
}

FString URequestGameInstance::GetReqReward(int32 idx)
{
	return FString();
}
