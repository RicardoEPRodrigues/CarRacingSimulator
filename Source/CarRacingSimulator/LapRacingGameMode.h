// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CarRacingSimulatorGameMode.h"
#include "LapRacingGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRaceFinished);

/**
 * 
 */
UCLASS()
class CARRACINGSIMULATOR_API ALapRacingGameMode : public ACarRacingSimulatorGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config")
	int Laps = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config")
	TArray<class ACheckpoint*> Checkpoints{};

	UFUNCTION(BlueprintCallable, Category = "Crs")
	void StartRace();

	UPROPERTY(BlueprintReadWrite, Category = "Config")
	float StartTime{};

	UPROPERTY(BlueprintReadWrite, Category = "Config")
	bool HasStarted = false;

	UFUNCTION(BlueprintPure, Category = "Crs")
	float GetRaceTime() const;

	UFUNCTION(BlueprintPure, Category = "Crs")
	FString GetRaceTimeString() const;

	UPROPERTY(BlueprintCallable, BlueprintAssignable, Category = "Crs")
	FOnRaceFinished OnRaceFinished;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnCarOverlap(ACheckpoint* Checkpoint, ACarRacingSimulatorPawn* Car);
};
