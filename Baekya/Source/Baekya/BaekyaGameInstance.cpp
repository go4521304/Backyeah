// Fill out your copyright notice in the Description page of Project Settings.

#include "BaekyaGameInstance.h"

UBaekyaGameInstance::UBaekyaGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("/Script/Engine.DataTable'/Game/Data/RequestData.RequestData'"));

	QuestTable = DATA.Object;
}

FREQUEST* UBaekyaGameInstance::GetReq(int32 idx)
{
	return QuestTable->FindRow<FREQUEST>(*FString::FromInt(idx), TEXT(""));;
}

FString UBaekyaGameInstance::GetReqTitle(int32 idx)
{
	return GetReq(idx)->Title;
}

FString UBaekyaGameInstance::GetReqBody(int32 idx)
{
	return GetReq(idx)->Body;
}

int32 UBaekyaGameInstance::GetReqTime(int32 idx)
{
	return GetReq(idx)->Time;
}

FString UBaekyaGameInstance::GetReqStory(int32 idx)
{
	return FString();
}

FString UBaekyaGameInstance::GetReqReward(int32 idx)
{
	return FString();
}
