// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "battle_royale_DZHUD.generated.h"

UCLASS()
class Abattle_royale_DZHUD : public AHUD
{
	GENERATED_BODY()

public:
	Abattle_royale_DZHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

