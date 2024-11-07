// Fill out your copyright notice in the Description page of Project Settings.


#include "NCharacter.h"
#include "EngineUtils.h"
#include "NCharacterStatComponent.h"
#include "TestActor.h"
#include "NPlayerState.h"
// Test 중
// #include "Components/WidgetComponent.h

// Sets default values
ANCharacter::ANCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 이 코드들은 캐릭터 테스트 코드임. 제거예정
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	testcode = 0;
	// 이 코드들은 캐릭터 테스트 코드임. 제거예정

	// StatComponent
	CharacterStat = CreateDefaultSubobject<UNCharacterStatComponent>(TEXT("CHARACTERSTAT"));
	
	// PostInitializeComponents() 함수에 넣어야 하는 코드
	CharacterStat->EmotionZero.AddLambda([this]() -> void {
		NLOG(Warning, TEXT("EmotionIsZero"));
		// Anim인스턴스 추가 후 주석 제거
		// NAnim->SetSetDeadAnim();
		SetActorEnableCollision(false);
		});

	// 상호작용
	Lock = false;
	LockTestActor = nullptr;
}

// Called when the game starts or when spawned
void ANCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 상호작용 대상 탐색
	InteractionLock();
}

// Called to bind functionality to input
void ANCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ANCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &ANCharacter::LeftRight);
	PlayerInputComponent->BindAction(TEXT("TEST"), EInputEvent::IE_Pressed, this, &ANCharacter::TEST);

	// 상호작용
	PlayerInputComponent->BindAction(TEXT("Interaction"), EInputEvent::IE_Pressed, this, &ANCharacter::Interaction);
}

/*
*  캐릭터 이동
*/
void ANCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
}

void ANCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
}

// 이 코드들은 캐릭터 테스트 코드임. 제거예정
void ANCharacter::TEST()
{
	NLOG_S(Warning);
	if (testcode == 0)
	{
		Bottle1 = (ANBottle*)GetWorld()->SpawnActor<ANBottle>(FVector(30, 1380, 50), FRotator(0, -90, 0));
		Bottle2 = (ANBottle*)GetWorld()->SpawnActor<ANBottle>(FVector(30, -1400, 50), FRotator(0, 90, 0));

		testcode = 1;
	}
	else
	{	
		if (IsValid(Bottle1) && IsValid(Bottle2))
		{
			Bottle1->Destroy();
			Bottle2->Destroy();
		}
		testcode = 0;
	}
}
// 이 코드들은 캐릭터 테스트 코드임. 제거예정

/*
* 상호작용
*/
void ANCharacter::Interaction()
{
	if (LockTestActor != nullptr)
	{
		NLOG_S(Warning);
		Lock = false;
		LockTestActor = nullptr;
		return;
	}
}

void ANCharacter::InteractionLock()
{
	for (ATestActor* Actor : TActorRange<ATestActor>(GetWorld()))
	{
		if ((GetActorLocation() - Actor->GetActorLocation()).Size() <= 300 && !Lock)
		{
			Lock = true;
			LockTestActor = Actor;
			return;
		}
	}
	if ((LockTestActor != nullptr) && (GetActorLocation() - LockTestActor->GetActorLocation()).Size() > 300)
	{
		Lock = false;
		LockTestActor = nullptr;
	}
}

// 스텟 관련 코드
/*void ANCharacter::SetCharacterState(ECharacterState NewState)
{
	NCHECK(CurrentState != NewState);
	CurrentState = NewState;

	switch (CurrentState)
	{
	case ECharacterState::LOADING:
	{
		if (bIsPlayer)
		{
			DisableInput(ANlayerController);

			auto NPlayerState = Cast<ANPlayerState>(GetPlayerState());
			NCHECK(nullptr != NPlayerState);
			CharacterStat->SetNewLevel(NPlayerState->GetCharacterLevel());
		}

		//SetActorHiddenInGame(true);
		//HPBarWidget->SetHiddenInGame(true);
		//SetCanBeDamaged(false);
		break;
	}
}
*/