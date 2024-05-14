// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include  "UObject\ConstructorHelpers.h"
#include "DrawDebugHelpers.h"


//Engine Includes
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMesh.h"

//Math Includes
#include "Math/TransformNonVectorized.h"

//Component Includes
#include "GameFramework\SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components\InputComponent.h"



#define DRAW_PERSISTANT_SPHERE(Position) if (GetWorld()) {\
	DrawDebugSphere(GetWorld(), Position, 32.f, 12.f, FColor::Red, true);\
}
#define DRAW_PERSISTANT_LINE(Start, End) if (GetWorld()) {\
	 DrawDebugLine(GetWorld(), Start, End, FColor::Red, true);\
}
#define DRAW_PRESISTANT_VECTOR(Start, End) if (GetWortld()) \
{\
	 DrawDebugLine(GetWorld(), Start, End, FColor::Red, true);\
	 DrawDebugPoint(GetWorld(), End, 1, FColor::Red, true);\
}

#define DRAW_SingleFrame_Shpere(Position, LifeTime) if (GetWorld()) {\
	DrawDebugSphere(GetWorld(), Position, 32.f, 12.f, FColor::Red, false, LifeTime);\
}
#define DRAW_SingleFrame_Line(Start, End, LifeTime) if (GetWorld()) {\
	DrawDebugLine(GetWorld, Start, End, FColor::Red, false, LifeTime);\
}
#define DRAW_SingleFrame_Vector(Start, End, LifeTime) if (GetWorld()) {\
	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, LifeTime);\
	DrawDebugPoint(GetWorld(), End, 1, FColor::Red, false, LifeTime);\
}


//Print
#define Quicklog(Message) UE_LOG(LogTemp, Warning, TEXT(Message))
#define QuickScreenLog(Key, Duration, Message) if (GEngine) { GEngine->AddOnScreenDebugMessage(Key, Duration, FColor::Cyan, FString(Message)}


//Make sure to add the module "EnhancedInput" to the build file
//Ex: MyProject2.Build.cs -- CSharp file

//Enhanced Input
//#define IMPORTANT_INPUT_CLASSES class UInputMappingContext; class UInputAction; class UEnhancedInputComponent;
#define LOCAL_SUBSYSTEM UEnhancedInputLocalPlayerSubsystem
#define INPUT_FORWARD_DECLARATIONS class UInputAction; class UInputMappingContext; class UInputComponent; 



class MYPROJECT2_API Shortcuts {

public:



};

