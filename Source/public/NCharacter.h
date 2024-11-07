// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "GameFramework/Character.h"

// 이 코드들은 캐릭터 테스트 코드임. 제거예정
#include "NBottle.h"
// 이 코드들은 캐릭터 테스트 코드임. 제거예정

#include "NCharacter.generated.h"

UCLASS()
class PROJECTN_API ANCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 이 코드들은 캐릭터 테스트 코드임. 제거예정
	UPROPERTY(VisibleAnywhere, Category = TEST)
		UStaticMeshComponent* MeshComponent;

	void TEST();
	int testcode;

	ANBottle* Bottle1;
	ANBottle* Bottle2;
	// 이 코드들은 캐릭터 테스트 코드임. 제거예정

	// StatComponent
	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UNCharacterStatComponent* CharacterStat;
	//void SetCharacterState(ECharacterState NewState);
	//ECharacterState GetCharacterState() const;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);



// 상호작용
public:
	void Interaction();
	void InteractionLock();

private:
	bool Lock;
	class ATestActor* LockTestActor;
};
