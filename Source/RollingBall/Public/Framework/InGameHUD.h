// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class ROLLINGBALL_API AInGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// Pauseメニューの表示/非表示
	void DispPause(const bool IsPause);

	// Levelを開く
	void OpenLevel(const FName LevelName);

	// Gameを終了する
	void QuitGame();

	// GameOverメニューを表示する
	void DispGameOver();

	// Gameを再開する
	void ContinueGame();
	
protected:
	virtual void BeginPlay() override;

private:
	// PauseWidgetを保持する変数
	UUserWidget* PauseWidget;

	// GameOverWidgetを保持する変数
	UUserWidget* GameOverWidget;
};
