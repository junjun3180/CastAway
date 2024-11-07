// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "Engine/GameInstance.h"
#include "NGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTN_API UNGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UNGameInstance();

	// 11.10 - 필요 시 추가 후 사용
	//virtual void Init() override;

};
