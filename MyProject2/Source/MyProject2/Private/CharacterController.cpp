// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterController.h"

#include "Kismet\GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Components/PrimitiveComponent.h"

#include "Timer/TimerComponent.h"

#include "LaneVisual.h"
#include "CharacterActor.h"
#include "LaneObstacleBase.h"
#include "LaneObstacleSpawner.h"


// Sets default values
ACharacterController::ACharacterController()
{
	PrimaryActorTick.bCanEverTick = true;



	this->RunningCharacter = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RunningCharacter"));
	this->RunningCharacter->SetupAttachment(GetRootComponent());
	this->RunningCharacter->ComponentTags.Add(FName(TEXT("Player")));

	this->OverlapSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Hitbox"));
	this->OverlapSphere->SetupAttachment(this->RunningCharacter);

	this->SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	this->SpringArm->SetupAttachment(GetRootComponent());
	this->SpringArm->TargetArmLength = 1000.f;

	this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	this->Camera->SetupAttachment(this->SpringArm);

	this->Spawner = CreateDefaultSubobject<ULaneObstacleSpawner>(TEXT("Spawner"));
	this->TimerComponent = CreateDefaultSubobject<UTimerComponent>(TEXT("TimerComponent"));


	static ConstructorHelpers::FObjectFinder<UStaticMesh> InstancedMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (InstancedMesh.Succeeded() && InstancedMesh.Object != NULL) {
		this->RunningCharacter->SetStaticMesh(InstancedMesh.Object);
	}

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void ACharacterController::SetUpInputs() {

	//Getting the Input Component
	UInputComponent* PlayerInputComponent = ACharacterController::InputComponent;

	Quicklog("Setting Up Inputs");

	//Casting the player controller to check if valid
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())) {

		//Getting a Input subsystem (With the shortcuts)
		if (LOCAL_SUBSYSTEM* Subsystem = ULocalPlayer::GetSubsystem<LOCAL_SUBSYSTEM>(PlayerController->GetLocalPlayer())) {
			Subsystem->AddMappingContext(CharacterMovement, 0);

			//Checking if the UEnhancedComponent is valid (CastChecked will crashed if the cast comes back valid)
			if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {

				Quicklog("Binding Inputs");

				//Binding Inputs

				//Jump
				EnhancedInputComponent->BindAction(Jump, ETriggerEvent::Triggered, this, &ACharacterController::DoJump);

				//MoveLeft
				EnhancedInputComponent->BindAction(MoveRight, ETriggerEvent::Triggered, this, &ACharacterController::SwitchLanes);

				//MoveRight
				EnhancedInputComponent->BindAction(MoveLeft, ETriggerEvent::Triggered, this, &ACharacterController::SwitchLanes);

				
			}

		}
	}

}

void ACharacterController::SetUpLanes() {

	ALaneVisual* LastLane = nullptr;

	for (int i = 0; i < this->AmountOfLanes; i++) {
		//Making a new Lane actor
		if (UWorld* World = GetWorld()) {
			if (ALaneVisual* NewLane = World->SpawnActor<ALaneVisual>(this->LaneOrigin, FRotator(0, 0, 0))) {
				Quicklog("Spawning Lane Visual");
				this->Lanes.Add(NewLane);
			}
		}

		//Checking if the last lane has been set. Then offsetting the current index with the last lane
		if (LastLane) {
			Quicklog("Setting Lane Location")
				//this->Lanes[i]->SetActorLocation();
				Cast<ALaneVisual>(this->Lanes[i])->SetActorLocation(this->LaneOffest + LastLane->GetActorLocation());
		}

		LastLane = this->Lanes[i];
	}

	//Moving Camera to the Middle Lane
	if (ALaneVisual* MiddleLane = this->Lanes[1]) {
		this->SpringArm->SetWorldLocation(MiddleLane->GetActorLocation());

		if (this->RunningCharacter == NULL) { return; }
		this->RunningCharacter->SetWorldLocation(MiddleLane->GetActorLocation());
		//Cast<ACharacterActor>(this->RunningCharacter)->SetActorLocation(MiddleLane->GetActorLocation());

	}


	LastLane = nullptr;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void ACharacterController::SwitchLanes(const FInputActionValue& Value) {
	
	const float CurrentValue = Value.Get<float>();

	if (CurrentValue > 0) {

		UE_LOG(LogTemp, Warning, TEXT("Left: %f"), CurrentValue);
		this->CurrentLane -= 1;
	}

	if (CurrentValue < 0) {
		UE_LOG(LogTemp, Warning, TEXT("Right: %f"), CurrentValue);
		this->CurrentLane += 1;
	}

	if (this->CurrentLane < 0) {
		this->CurrentLane = 0;
		return;
	}

	if (this->CurrentLane > 2) {
		this->CurrentLane = 2;
		return;
	}

	FVector NewPosition = this->Lanes[this->CurrentLane]->GetActorLocation();
	if (this->RunningCharacter != NULL) {
		this->RunningCharacter->SetWorldLocation(NewPosition);
	}

	UE_LOG(LogTemp, Warning, TEXT("Current Lane %d"), this->CurrentLane);
}

void ACharacterController::DoJump(const FInputActionValue& Value) {
	const bool JumpAttempt = Value.Get<bool>();
	if (JumpAttempt) {
		UE_LOG(LogTemp, Warning, TEXT("Jump"));
	}

	if (!JumpAttempt) {
		UE_LOG(LogTemp, Warning, TEXT("Not Jumping"));
	}
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------

void ACharacterController::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AActor* actor = Cast<AActor>(OtherActor)) {
		if (!actor->ActorHasTag(FName(TEXT("Obstacle")))) {return;}
	}

	this->DamagePlayer();
}

void ACharacterController::DamagePlayer() {
	//Make a Game over screen


	Quicklog("Damage");

	for (int i = 0; i < this->Lanes.Num(); i++) {
		this->Lanes[i]->Destroy();
	}

	this->Lanes.Empty();

	

	if (UWorld* world = GetWorld()) {
		//UGameplayStatics::SetGamePaused(world, true);
		UGameplayStatics::OpenLevel(world, "MainMenu", true);
	}
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------


void ACharacterController::BeginPlay()
{

	Super::BeginPlay();

	this->OverlapSphere->OnComponentBeginOverlap.AddDynamic(this, &ACharacterController::OnOverlap);
	//this->SetActorEnableCollision(false);


	//this->Spawner->HandleSpawning(this->Lanes);
}

//----------------------------------------------------------

//----------------------------------------------------------


void ACharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
