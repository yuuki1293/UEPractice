// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InGamePlayerController.generated.h"

struct FInputActionValue;
class UInputAction;

/**
 * 
 */
UCLASS()
class ROLLINGBALL_API AInGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Constructor
	AInGamePlayerController();

	// APlayerControllerからOverrideする
	virtual void SetupInputComponent() override;
	
protected:
	virtual void BeginPlay() override;

	// Pauseメニューを表示する
	void DispPause(const FInputActionValue& Value);

private:
    /** Pause Input Action */
    UPROPERTY(EditAnywhere, Category = Input, meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UInputAction> PauseAction;
};
