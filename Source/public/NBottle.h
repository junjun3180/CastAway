// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "GameFramework/Actor.h"
#include "NBottle.generated.h"

UCLASS()
class PROJECTN_API ANBottle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANBottle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


//----------------------------------------------------------------------------------------------

public:
	void RemoveBottle();

private:
	// 이 코드들은 캐릭터 테스트 코드임. 제거예정
	UPROPERTY(VisibleAnywhere, Category = TEST)
		UStaticMeshComponent* MeshComponent;

	// 이 코드들은 캐릭터 테스트 코드임. 제거예정

	bool IsMoving;
};
