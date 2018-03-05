// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DZPatrolRoute.generated.h"

/**
	A "route card" to help AI choose their next waypoint
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_ROYALE_DZ_API UDZPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:	

	TArray<AActor*> GetPatrolPoints() const;


private:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
		TArray<AActor*> PatrolPointsDZ;
	
};


