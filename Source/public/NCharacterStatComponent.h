// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "Components/ActorComponent.h"
#include "NCharacterStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnEmotionZeroDelegate);
DECLARE_MULTICAST_DELEGATE(FOnEmotionChangedDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTN_API UNCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	virtual void InitializeComponent() override;
	
public:
	void SetFirstStart ();
	float GetHPRatio(int32);
	void ChangEmotion(float NewDamage, int32 Emotion);
	void SetEmotion(float NewEmotion, int32 Emotion);

	FOnEmotionZeroDelegate EmotionZero;
	FOnEmotionChangedDelegate OnEmotionChanged;

private:
	// 삭제 예정 - 안씀
	struct FNCharacterData* CurrentStatData = nullptr;
	
	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = true))
	TArray<float> EmotionStatus;
};
