// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyShortcuts.h"

#include "LaneVisual.generated.h"

UCLASS()
class MYPROJECT2_API ALaneVisual : public AActor
{
	GENERATED_BODY()
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	// Sets default values for this actor's properties
	ALaneVisual();

	UPROPERTY(VisibleAnywhere, Category = Components)
	UStaticMeshComponent* MeshVisual;



};
