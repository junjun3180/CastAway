// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectN.h"
#include "GameFramework/PlayerController.h"
#include "NPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTN_API ANPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ANPlayerController();

	virtual void BeginPlay() override;
	class UNHUDWidget* GetHUDWidget() const;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UNHUDWidget> HUDWidgetClass;

private:
	UPROPERTY()
	class UNHUDWidget* HUDWidget;
};
