﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "LapRacingGameMode.h"

#include "CarRacingSimulatorPawn.h"
#include "Checkpoint.h"

void ALapRacingGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ALapRacingGameMode::StartRace()
{
	for (const auto Checkpoint : Checkpoints)
	{
		Checkpoint->OnCarOverlap.AddDynamic(this, &ALapRacingGameMode::OnCarOverlap);
	}

	HasStarted = true;
	StartTime = GetWorld()->TimeSeconds;
}

float ALapRacingGameMode::GetRaceTime() const
{
	if (!HasStarted)
	{
		return 0;
	}
	return GetWorld()->TimeSeconds - StartTime;
}

FString ALapRacingGameMode::GetRaceTimeString() const
{
	const float RaceTime = GetRaceTime();
	const int Minutes = RaceTime / 60;
	const int Seconds = (int)RaceTime % 60;
	const int Milliseconds = (RaceTime - ((float)Minutes * 60.0f) - (float)Seconds) * 1000.0f;
	FString MillisecondsString = FString::FromInt(Milliseconds);
	MillisecondsString = MillisecondsString.Left(1);
	return FString::Printf(TEXT("%02d:%02d.%s"), Minutes, Seconds, *MillisecondsString);
}

void ALapRacingGameMode::OnCarOverlap(ACheckpoint* Checkpoint, ACarRacingSimulatorPawn* Car)
{
	if (Car->CurrentCheckpoint == Checkpoint)
	{
		return;
	}

	if (Car->CurrentCheckpoint == nullptr)
	{
		Car->CurrentCheckpoint = Checkpoint;
		return;
	}
	
	// Check if Car is going in the right direction by looking at the previous checkpoint
	const int CheckpointIndex = Checkpoints.Find(Checkpoint);
	if (CheckpointIndex == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("Checkpoint not found in Checkpoints array"));
		return;
	}

	const int PreviousCheckpointIndex = Checkpoints.Find(Car->CurrentCheckpoint);
	if (PreviousCheckpointIndex == INDEX_NONE)
	{
		UE_LOG(LogTemp, Warning, TEXT("Car Checkpoint not found in Checkpoints array"));
		return;
	}

	const bool bIsGoingInWrongDirectionEdgeCase = CheckpointIndex == Checkpoints.Num() - 1 && PreviousCheckpointIndex == 0;
	const bool bIsGoingInWrongDirection = CheckpointIndex != 0 && CheckpointIndex < PreviousCheckpointIndex;
	if (bIsGoingInWrongDirectionEdgeCase || bIsGoingInWrongDirection)
	{
		UE_LOG(LogTemp, Warning, TEXT("Car is going in the wrong direction"));
		Car->ResetVehicleAtCurrentCheckpoint();
		return;
	}

	Car->CurrentCheckpoint = Checkpoint;
	if (Checkpoint->Type == ECheckpointType::Start)
	{
		Car->CurrentLap++;
		if (Car->CurrentLap >= Laps)
		{
			OnRaceFinished.Broadcast();
		}
	}
}
