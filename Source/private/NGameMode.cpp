// Fill out your copyright notice in the Description page of Project Settings.


#include "NGameMode.h"
#include "NCharacter.h"
#include "NPlayerController.h"
#include "NPlayerState.h"

ANGameMode::ANGameMode()
{
	DefaultPawnClass = ANCharacter::StaticClass();
	PlayerControllerClass = ANPlayerController::StaticClass();
	PlayerStateClass = ANPlayerState::StaticClass();
}

void ANGameMode::PostLogin(APlayerController* NewPlayer)
{
	auto NPlayerState = Cast<ANPlayerState>(NewPlayer->PlayerState);
	NPlayerState->InitPlayerData();
}