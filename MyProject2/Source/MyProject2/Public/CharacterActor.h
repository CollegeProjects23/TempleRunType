// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MyShortcuts.h"

#include "CharacterActor.generated.h"

UCLASS()
class MYPROJECT2_API ACharacterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACharacterActor();
	virtual void Tick(float DeltaTime) override;
	virtual void TestFunc();

	

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterComponents)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterComponents)
	TObjectPtr<UStaticMesh> Cube;

private:
};
