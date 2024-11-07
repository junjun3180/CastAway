// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TestActor = CreateDefaultSubobject< UStaticMeshComponent>(TEXT("TestActor"));

	UStaticMesh* SM_TestActor = Cast< UStaticMesh >(StaticLoadObject(UStaticMesh::StaticClass(), NULL, TEXT("/Game/Assets/Okk/botttle/1/SM_bottle.SM_bottle")));
	if (SM_TestActor) {
		TestActor->SetStaticMesh(SM_TestActor);
	}
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

