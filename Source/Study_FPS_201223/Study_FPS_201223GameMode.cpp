// Copyright Epic Games, Inc. All Rights Reserved.

#include "Study_FPS_201223GameMode.h"
#include "Study_FPS_201223HUD.h"
#include "Study_FPS_201223Character.h"
#include "UObject/ConstructorHelpers.h"

AStudy_FPS_201223GameMode::AStudy_FPS_201223GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStudy_FPS_201223HUD::StaticClass();
}
