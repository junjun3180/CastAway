// Fill out your copyright notice in the Description page of Project Settings.


#include "NCharacterStatComponent.h"
#include "NGameInstance.h"

// Sets default values for this component's properties
UNCharacterStatComponent::UNCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}


// Called when the game starts
void UNCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UNCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetFirstStart();
}

// 처음 시작할 때는 고려할 필요가 없음.
// 데이터를 받아서 불러오는 함수로 만들어야 함.
void UNCharacterStatComponent::SetFirstStart()
{
	// 초기값 지정
	EmotionStatus.Init(100.0f, 4);
}

void UNCharacterStatComponent::ChangEmotion(float NewDamage, int32 Emotion)
{
	SetEmotion(FMath::Clamp<float>(EmotionStatus[Emotion] + NewDamage, 0.0f, 100.0f), Emotion);
}

void UNCharacterStatComponent::SetEmotion(float NewEmotion, int32 Emotion)
{
	EmotionStatus[Emotion] = NewEmotion;
	OnEmotionChanged.Broadcast();

	if (EmotionStatus[Emotion] <= 0.0f)
		EmotionZero.Broadcast();
}

float UNCharacterStatComponent::GetHPRatio(int32 EmotionNum)
{
	return (100.0f < KINDA_SMALL_NUMBER) ? 0.0f : (EmotionStatus[EmotionNum] / 100.0f);
}