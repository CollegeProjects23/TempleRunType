// Fill out your copyright notice in the Description page of Project Settings.
#include "LaneObstacleSpawner.h"
#include "LaneVisual.h"
#include "CharacterController.h"
#include "LaneObstacleBase.h"

ULaneObstacleSpawner::ULaneObstacleSpawner()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void ULaneObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void ULaneObstacleSpawner::HandleSpawning(TArray<ALaneVisual*> Lanes) {

	//Get a random number (0-2)
	//Make a new Obstacle and position it in front of the lane
	int32 RandomNumber = FMath::RandRange(0, 2);
	ALaneVisual* Lane = Lanes[RandomNumber];

	if (UWorld* world = GetWorld()) {

		ALaneObstacleBase* newObstacle = world->SpawnActor<ALaneObstacleBase>(Lane->GetActorLocation() + this->SpawnOffset, FRotator(0,0,0));
		this->SpawnedObstacles.Add(newObstacle);
	}
}

void ULaneObstacleSpawner::HandleObstacleVelocity(float DeltaTime) {

	if (this->SpawnedObstacles.Num() <= 0) { return; }

	for (int i = 0; i < this->SpawnedObstacles.Num(); i++) {
		FVector ObstacleLocation = this->SpawnedObstacles[i]->GetActorLocation();
		this->SpawnedObstacles[i]->SetActorLocation(ObstacleLocation + (this->MovementRate * DeltaTime));

		FVector CurrentPosition = this->SpawnedObstacles[i]->GetActorLocation();
		if (CurrentPosition.X < this->PositionLimit.X) {
			this->SpawnedObstacles[i]->Destroy();
			this->SpawnedObstacles.RemoveAt(i);			
		}
	}

}

void ULaneObstacleSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
