// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu/MainMenuGameMode.h"
#include "MainMenu/MainMenuHUD.h"

AMainMenuGameMode::AMainMenuGameMode()
{
	HUDClass = AMainMenuHUD::StaticClass();
}
