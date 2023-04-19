// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "RequestGameInstance.generated.h"

USTRUCT()
struct FREQUEST : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Body;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Time;
};


/**
 * 
 */
UCLASS()
class BAEKYA_API URequestGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	URequestGameInstance();

	FREQUEST* GetReq(int32 idx);

	FString GetReqTitle(int32 idx);
	FString GetReqBody(int32 idx);
	int32 GetReqTime(int32 idx);

	FString GetReqStory(int32 idx);
	FString GetReqReward(int32 idx);
private:
	UPROPERTY()
	UDataTable* QuestTable;
};
