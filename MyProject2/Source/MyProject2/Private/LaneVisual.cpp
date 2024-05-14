// Fill out your copyright notice in the Description page of Project Settings.


#include "LaneVisual.h"

// Sets default values
ALaneVisual::ALaneVisual()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->MeshVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshVisualComp"));
	this->MeshVisual->SetupAttachment(this->GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	/*if (CubeMesh.Succeeded()) {
		this->MeshVisual->SetStaticMesh(CubeMesh.Object);
	}*/
}

// Called when the game starts or when spawned
void ALaneVisual::BeginPlay()
{
	Super::BeginPlay();
	this->SetActorEnableCollision(false);

	
}

// Called every frame
void ALaneVisual::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

