// Fill out your copyright notice in the Description page of Project Settings.


#include "NBottle.h"

// Sets default values
ANBottle::ANBottle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 이 코드들은 캐릭터 테스트 코드임. 제거예정
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	IsMoving = false;
	// 이 코드들은 캐릭터 테스트 코드임. 제거예정
}

// Called when the game starts or when spawned
void ANBottle::BeginPlay()
{
	Super::BeginPlay();
	
	IsMoving = true;
}

// Called every frame
void ANBottle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsMoving)
	{
		float Distance = FVector::Distance(FVector(30, 600, 50), FVector(GetActorLocation().X, FMath::Abs(GetActorLocation().Y), GetActorLocation().Z));

		if (Distance <= 10.0f)
		{
			IsMoving = false;
		}
		else
		{
			SetActorLocation(GetActorLocation() + (GetActorForwardVector() * 300.0f * DeltaTime));
		}
	}

}

void ANBottle::RemoveBottle()
{
	this->Destroy();
}

