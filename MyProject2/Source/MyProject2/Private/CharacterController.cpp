// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"
#include "EnhancedInputSubsystems.h"

#define LocalSubsystem UEnhancedInputLocalPlayerSubsystem

// Sets default values
ACharacterController::ACharacterController()
{
	PrimaryActorTick.bCanEverTick = true;


}

//----------------------------------------------------------
void ACharacterController::SetUpInputs() {	

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {
		if (LocalSubsystem* Subsystem = ULocalPlayer::GetSubsystem<LocalSubsystem>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(CharacterMovement, 0);

		}
	}



}

void ACharacterController::SwitchLanes(const FInputActionValue& Value) {

	UE_LOG(LogTemp, Warning, TEXT("Value %f"), Value)

}

//----------------------------------------------------------


void ACharacterController::BeginPlay()
{
	Super::BeginPlay();
	ACharacterController::SetUpInputs();

}


void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
