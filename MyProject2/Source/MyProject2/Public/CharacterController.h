// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

//---------------------------------
#include "GameFramework\SpringArmComponent.h"
//---------------------------------
#include "MyShortcuts.h"
#include "CharacterController.generated.h"
//-----------------------

struct FTimerTemplate;


class UGameplayStatics;
class USpringArmComponent;
class UTimerComponent;
class ULaneObstacleSpawner;
class UCameraComponent;
class UStaticMeshComponent;
class USphereComponent;
INPUT_FORWARD_DECLARATIONS

class ALaneVisual;

UCLASS()
class MYPROJECT2_API ACharacterController : public APawn
{
	GENERATED_BODY()

public:

	 ACharacterController();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void SetUpInputs();

	UFUNCTION(BlueprintCallable)
	virtual void SetUpLanes();

	UFUNCTION(BlueprintCallable)
	virtual void DamagePlayer();


private:

	UPROPERTY(VisibleAnywhere, Category = Character)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Character)
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, Category = Character)
	UStaticMeshComponent* Cube;

	UPROPERTY(EditDefaultsOnly, Category = Character)
	USphereComponent* OverlapSphere;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ActorReferences)
	ULaneObstacleSpawner* Spawner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ActorReferences)
	UTimerComponent* TimerComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ActorReferences)
	UStaticMeshComponent* RunningCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ActorReferences)
	TArray<ALaneVisual*> Lanes;

	//--------------------------------

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharacterData)
	float Speed = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharacterData)
	int CurrentLane = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharacterData)
	int AmountOfLanes = 3;

	UPROPERTY(EditInstanceOnly, Category = CharacterData)
	FVector LaneOffest = FVector(0, 500, 0);

	UPROPERTY(VisibleAnywhere, Category = CharacterData)
	FVector LaneOrigin = FVector(0, 0, 0);

	//--------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* CharacterMovement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* Jump;
	//--------------------------------

	//Input Methods
	virtual void SwitchLanes(const FInputActionValue& value);
	virtual void DoJump(const FInputActionValue& value);


	//On Overlap
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};