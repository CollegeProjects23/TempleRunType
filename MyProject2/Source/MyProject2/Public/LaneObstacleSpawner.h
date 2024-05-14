// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

//#include "ForwardDeclerations.h"
#include "LaneObstacleSpawner.generated.h"

class ALaneVisual;
class ALaneObstacleBase;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT2_API ULaneObstacleSpawner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULaneObstacleSpawner();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = ObstacleFunctions)
	virtual void HandleSpawning(TArray<ALaneVisual*> Lanes);

	UFUNCTION(BlueprintCallable, Category = ObstacleFunctions)
	virtual void HandleObstacleVelocity(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = Presets)
	FVector SpawnOffset = FVector(1500, 0, 0);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MainInformation)
	TArray<ALaneObstacleBase*> SpawnedObstacles;

	UPROPERTY(EditAnywhere, Category = MainInformation)
	FVector MovementRate = FVector(-1000, 0, 0);

	UPROPERTY(EditAnywhere, Category = MainInformation)
	FVector PositionLimit = FVector(-600, 0, 0);

protected:

	virtual void BeginPlay() override;
	
};