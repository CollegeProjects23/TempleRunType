// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer/TimerComponent.h"
#include "MyShortcuts.h"

UTimerComponent::UTimerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTimerComponent::AddTimer(FTimerTemplate newTimer) {
	bool timerAlreadyExsists = false;

	for (int32 i = 0; i < this->Timers.Num(); i++) {
		if (this->Timers[i].TimerName != newTimer.TimerName) { continue; }	
		timerAlreadyExsists = true;
		break;
	}

	if (!timerAlreadyExsists) {
		this->Timers.Add(newTimer);
	}
}

FTimerTemplate UTimerComponent::GetTimer(FName TimerName) {
	FTimerTemplate TimerImLookingFor;

	for (int32 i = 0; i < this->Timers.Num(); i++) {
		if (this->Timers[i].TimerName != TimerName) { continue; }
		TimerImLookingFor = this->Timers[i];
		break;
	}

	return TimerImLookingFor;
}

void UTimerComponent::TickTimers(float DeltaTime) {

	
	
}

void UTimerComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTimerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	for (int32 i = 0; i < this->Timers.Num(); i++) {
		bool bTicked = false;

		FTimerTemplate currentTimer = this->Timers[i];
		if (!currentTimer.bCanTick) { continue; }

		switch (currentTimer.TimerType) {

		case ETimerType::Up:

			currentTimer.fCurrentTime += DeltaTime;
			if (currentTimer.fCurrentTime >= currentTimer.TargetTime) {
				currentTimer.fCurrentTime = currentTimer.StartTime;

				bTicked = true;
			}

			break;

		case ETimerType::Down:

			currentTimer.fCurrentTime -= DeltaTime;
			if (currentTimer.fCurrentTime <= currentTimer.TargetTime) {
				currentTimer.fCurrentTime = currentTimer.StartTime;

				bTicked = true;
			}

			break;

		}

		FTimerTemplate newTemplate = currentTimer;
		this->Timers.RemoveAt(i);
		this->Timers.Insert(newTemplate, i);

		if (bTicked) {
			//Quicklog("Ticking");

			this->onTimerTick.Broadcast(this->Timers[i].TimerName);


			if (this->Timers[i].DestroyOnTick) {
				this->Timers.RemoveAt(i);
			}
		}

	}

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}