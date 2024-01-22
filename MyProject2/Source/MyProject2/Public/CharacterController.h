// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

//---------------------------------
#include "InputActionValue.h"
//---------------------------------

#include "CharacterController.generated.h"

class UInputMappingContext;
class UInputAction;

	

UCLASS()
class MYPROJECT2_API ACharacterController : public APawn
{
	GENERATED_BODY()

public:
	ACharacterController();
	virtual void Tick(float DeltaTime) override;
	virtual void SetUpInputs();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
	float Speed = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterData)
	int CurrentLane = 1;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* CharacterMovement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveLeft;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= Input)
	UInputAction* Jump;

	virtual void SwitchLanes(const FInputActionValue& value);
};
