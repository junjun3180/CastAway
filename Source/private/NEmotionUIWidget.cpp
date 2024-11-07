// Fill out your copyright notice in the Description page of Project Settings.


#include "NEmotionUIWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "NCharacterStatComponent.h"
#include "NPlayerState.h"

void UNEmotionUIWidget::BindCharacterStat(UNCharacterStatComponent* CharacterStat)
{
	CurrentCharacterStat = CharacterStat;
	//CharacterStat->OnHPChanged.AddUObject(this, &UNEmotionUIWidget::UpdateCharacterStat);
}

void UNEmotionUIWidget::BindPlayerState(ANPlayerState* PlayerState)
{
	CurrentPlayerState = PlayerState;
	//PlayerState->OnPlayerStateChanged.AddUObject(this, &UNEmotionUIWidget::UpdatePlayerState);
}

void UNEmotionUIWidget::NativeConstruct()
{
	Super::NativeConstruct();
	EmotionBar0 = Cast<UProgressBar>(GetWidgetFromName(TEXT("Emotion0")));
	EmotionBar1 = Cast<UProgressBar>(GetWidgetFromName(TEXT("Emotion1")));
	EmotionBar2 = Cast<UProgressBar>(GetWidgetFromName(TEXT("Emotion2")));
	EmotionBar3 = Cast<UProgressBar>(GetWidgetFromName(TEXT("Emotion3")));
}

void UNEmotionUIWidget::UpdateCharacterStat()
{
	EmotionBar0->SetPercent(CurrentCharacterStat->GetHPRatio(0));
	EmotionBar1->SetPercent(CurrentCharacterStat->GetHPRatio(1));
	EmotionBar2->SetPercent(CurrentCharacterStat->GetHPRatio(2));
	EmotionBar3->SetPercent(CurrentCharacterStat->GetHPRatio(3));
}

void UNEmotionUIWidget::UpdatePlayerState()
{
	//EmotionBar0->SetPercent(CurrentPlayerState->GetExpRatio());
	//EmotionBar1->SetPercent(CurrentPlayerState->GetExpRatio());
	//EmotionBar2->SetPercent(CurrentPlayerState->GetExpRatio());
	//EmotionBar3->SetPercent(CurrentPlayerState->GetExpRatio());
}


