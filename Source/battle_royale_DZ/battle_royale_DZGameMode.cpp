// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "battle_royale_DZGameMode.h"
#include "battle_royale_DZHUD.h"
#include "battle_royale_DZCharacter.h"
#include "UObject/ConstructorHelpers.h"

Abattle_royale_DZGameMode::Abattle_royale_DZGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = Abattle_royale_DZHUD::StaticClass();
}
