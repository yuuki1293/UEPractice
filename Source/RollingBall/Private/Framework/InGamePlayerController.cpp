// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/InGamePlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Framework/InGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"

void AInGamePlayerController::BeginPlay()
{
	// 入力をGameのみにする
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(this, false);

	// マウスを非表示にする
	SetShowMouseCursor(false);
}

AInGamePlayerController::AInGamePlayerController()
{
	// Input Action「IA_Pause」を読み込む
	PauseAction = LoadObject<UInputAction>(nullptr, TEXT("/Game/RollingBall/Input/Action/IA_Pause"));
}

void AInGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Triggered, this, &AInGamePlayerController::DispPause);
	}
}

void AInGamePlayerController::DispPause(const FInputActionValue& Value)
{
	// inputのValueはboolに変換できる
	if (const bool V = Value.Get<bool>())
	{
		if (AInGameHUD* HUD = Cast<AInGameHUD>(GetHUD()))
		{
			// Pauseメニューの表示/非表示を実行する
			HUD->DispPause(!UGameplayStatics::IsGamePaused(GetWorld()));
		}
	}
}
