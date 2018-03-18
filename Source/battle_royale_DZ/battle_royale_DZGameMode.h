// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "battle_royale_DZGameMode.generated.h"

UCLASS(minimalapi)
class Abattle_royale_DZGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	Abattle_royale_DZGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
		void PopulateBoundsVolumePool();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
		class UActorPool*  NavMeshBoundsVolumePool;



private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
};



