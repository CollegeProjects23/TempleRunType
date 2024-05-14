// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterActor.h"

// Sets default values
ACharacterActor::ACharacterActor()
{
	PrimaryActorTick.bCanEverTick = false;

	this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	this->StaticMesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> InstanacedMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (InstanacedMesh.Succeeded()) {
		
		this->Cube = InstanacedMesh.Object;
		this->StaticMesh->SetStaticMesh(this->Cube);
	}

	this->Tags.Add(FName(TEXT("Player")));
}

void ACharacterActor::BeginPlay()
{
	this->SetActorEnableCollision(false);
	Super::BeginPlay();
}

void ACharacterActor::TestFunc() {

}

// Called every frame
void ACharacterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
;
