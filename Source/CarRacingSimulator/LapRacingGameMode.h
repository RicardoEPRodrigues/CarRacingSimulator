// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CarRacingSimulatorGameMode.h"
#include "LapRacingGameMode.generated.h"

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

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnCarOverlap(ACheckpoint* Checkpoint, ACarRacingSimulatorPawn* Car);
};
