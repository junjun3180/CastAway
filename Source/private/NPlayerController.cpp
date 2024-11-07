// Fill out your copyright notice in the Description page of Project Settings.


#include "NPlayerController.h"
#include "NHUDWidget.h"

ANPlayerController::ANPlayerController()
{
	static ConstructorHelpers::FClassFinder<UNHUDWidget> UI_HUD_C(TEXT("/Game/UI/UI_HUD.UI_HUD_C"));
	if (UI_HUD_C.Succeeded())
	{
		HUDWidgetClass = UI_HUD_C.Class;
	}
}

void ANPlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUDWidget = CreateWidget<UNHUDWidget>(this, HUDWidgetClass);
	//HUDWidget->AddToViewport();
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}

UNHUDWidget* ANPlayerController::GetHUDWidget() const
{
	return HUDWidget;
}