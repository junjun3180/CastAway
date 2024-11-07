// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "GameFramework/GameModeBase.h"
#include "NGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTN_API ANGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	ANGameMode();
	void PostLogin(APlayerController* NewPlayer);
};