// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "GameFramework/Character.h"

// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���
#include "NBottle.h"
// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���

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
	// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���
	UPROPERTY(VisibleAnywhere, Category = TEST)
		UStaticMeshComponent* MeshComponent;

	void TEST();
	int testcode;

	ANBottle* Bottle1;
	ANBottle* Bottle2;
	// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���

	// StatComponent
	UPROPERTY(VisibleAnywhere, Category = Stat)
	class UNCharacterStatComponent* CharacterStat;
	//void SetCharacterState(ECharacterState NewState);
	//ECharacterState GetCharacterState() const;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);



// ��ȣ�ۿ�
public:
	void Interaction();
	void InteractionLock();

private:
	bool Lock;
	class ATestActor* LockTestActor;
};
