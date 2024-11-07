// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "GameFramework/PlayerState.h"
#include "NPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTN_API ANPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ANPlayerState();

	//int32 GetGameScore() const;
	
	void InitPlayerData();

	//FOnPlayerStateChangedDelegate OnPlayerStateChanged;

protected:
	//UPROPERTY(Transient)
	//int32 GameScore;

	//UPROPERTY(Transient)
	//int32 CharacterLevel;
};
