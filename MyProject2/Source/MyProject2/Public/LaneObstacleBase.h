// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LaneObstacleBase.generated.h"

class UStaticMesh;
class UStaticMeshComponent;
class UCharacterController;
class UPrimativeComponent;

UCLASS()
class MYPROJECT2_API ALaneObstacleBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaneObstacleBase();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	UStaticMeshComponent* StaticMesh;

private:

	TObjectPtr<UStaticMesh> Cube;

};
