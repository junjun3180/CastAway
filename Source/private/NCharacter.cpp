// Fill out your copyright notice in the Description page of Project Settings.


#include "NCharacter.h"
#include "EngineUtils.h"
#include "NCharacterStatComponent.h"
#include "TestActor.h"
#include "NPlayerState.h"
// Test ��
// #include "Components/WidgetComponent.h

// Sets default values
ANCharacter::ANCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	testcode = 0;
	// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���

	// StatComponent
	CharacterStat = CreateDefaultSubobject<UNCharacterStatComponent>(TEXT("CHARACTERSTAT"));
	
	// PostInitializeComponents() �Լ��� �־�� �ϴ� �ڵ�
	CharacterStat->EmotionZero.AddLambda([this]() -> void {
		NLOG(Warning, TEXT("EmotionIsZero"));
		// Anim�ν��Ͻ� �߰� �� �ּ� ����
		// NAnim->SetSetDeadAnim();
		SetActorEnableCollision(false);
		});

	// ��ȣ�ۿ�
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

	// ��ȣ�ۿ� ��� Ž��
	InteractionLock();
}

// Called to bind functionality to input
void ANCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &ANCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &ANCharacter::LeftRight);
	PlayerInputComponent->BindAction(TEXT("TEST"), EInputEvent::IE_Pressed, this, &ANCharacter::TEST);

	// ��ȣ�ۿ�
	PlayerInputComponent->BindAction(TEXT("Interaction"), EInputEvent::IE_Pressed, this, &ANCharacter::Interaction);
}

/*
*  ĳ���� �̵�
*/
void ANCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
}

void ANCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
}

// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���
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
// �� �ڵ���� ĳ���� �׽�Ʈ �ڵ���. ���ſ���

/*
* ��ȣ�ۿ�
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

// ���� ���� �ڵ�
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