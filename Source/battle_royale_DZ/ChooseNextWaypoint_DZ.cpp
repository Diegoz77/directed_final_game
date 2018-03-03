// Fill out your copyright notice in the Description page of Project Settings.



#include "ChooseNextWaypoint_DZ.h"
#include "AIController.h"
#include "PatrollingGuard.h" // TODO remove coupling
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint_DZ::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	// TODO protect against empty patrol routes

	// Get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	// Set next Waypoint
	

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num(); 
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


	return EBTNodeResult::Succeeded;


}



