// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "Blueprint/UserWidget.h"
#include "NEmotionUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTN_API UNEmotionUIWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindCharacterStat(class UNCharacterStatComponent* CharacterStat);
	void BindPlayerState(class ANPlayerState* PlayerState);

protected:
	virtual void NativeConstruct() override;
	void UpdateCharacterStat();
	void UpdatePlayerState();

private:
	TWeakObjectPtr<class UNCharacterStatComponent> CurrentCharacterStat;
	TWeakObjectPtr<class ANPlayerState> CurrentPlayerState;

	UPROPERTY()
	class UProgressBar* EmotionBar0;

	UPROPERTY()
	class UProgressBar* EmotionBar1;
	
	UPROPERTY()
	class UProgressBar* EmotionBar2;

	UPROPERTY()
	class UProgressBar* EmotionBar3;
};
