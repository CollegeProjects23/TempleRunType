// Fill out your copyright notice in the Description page of Project Settings.


#include "LaneObstacleBase.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ALaneObstacleBase::ALaneObstacleBase()
{
 	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> InstancedMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (InstancedMesh.Succeeded() && InstancedMesh.Object) {
		
		this->Cube = InstancedMesh.Object;
		this->StaticMesh->SetStaticMesh(this->Cube);
	}
	
	this->Tags.Add(FName(TEXT("Obstacle")));
}



// Called when the game starts or when spawned
void ALaneObstacleBase::BeginPlay()
{
	Super::BeginPlay();	
	//this->SetActorEnableCollision(false);
}



// Called every frame
void ALaneObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

