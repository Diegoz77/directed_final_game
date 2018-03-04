// Fill out your copyright notice in the Description page of Project Settings.



#include "ChooseNextWaypoint_DZ.h"
#include "AIController.h"
#include "DZPatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint_DZ::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	// TODO protect against no component 
	



	// Get the patrol route

	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	auto PatrolRoute = ControlledPawn->FindComponentByClass<UDZPatrolRoute>();

	if (!ensure(PatrolRoute)) 
	{
		return EBTNodeResult::Failed; 
	}


	auto PatrolPoints = PatrolRoute->GetPatrolPoints();

	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}

	// Set next Waypoint
	
	// protect against empty patrol routes
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num(); 
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	return EBTNodeResult::Succeeded;


}



