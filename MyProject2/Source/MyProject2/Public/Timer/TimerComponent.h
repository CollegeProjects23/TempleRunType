// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimerRemote, FName, TimerName);


UENUM(BlueprintType)
enum class ETimerType: uint8
{
	None,
	Down UMETA(ToolTip = "Ticks Down"),
	Up UMETA(ToolTip = "Ticks Up"),
};

USTRUCT(BlueprintType)
struct FTimerTemplate {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TimerName = FName(TEXT("TimerName"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETimerType TimerType = ETimerType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DestroyOnTick = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StartTime = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TargetTime = 0.f;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fCurrentTime = 0.f UMETA(ToolTip = "Do Not Set This");

	bool bCanTick = true;
};




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT2_API UTimerComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UTimerComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable, Category = ComponentFunctions)
	virtual void AddTimer(FTimerTemplate newTimer);

	UFUNCTION(BlueprintCallable, Category = ComponentFunctions)
	virtual FTimerTemplate GetTimer(FName TimerName);

	UPROPERTY(BlueprintAssignable)
	FTimerRemote onTimerTick;
private:

	UPROPERTY(VisibleAnywhere, Category = "TimerInfo")
	TArray<FTimerTemplate> Timers;

	UFUNCTION(BlueprintCallable, Category = ComponentFunctions)
	virtual void TickTimers(float DeltaTime);

};
