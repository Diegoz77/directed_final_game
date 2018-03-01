// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint_DZ.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_ROYALE_DZ_API UChooseNextWaypoint_DZ : public UBTTaskNode
{
	GENERATED_BODY()
	
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, category = "Blackboard")
		struct FBlackboardKeySelector Index; 
	
	
	
};
