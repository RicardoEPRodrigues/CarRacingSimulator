// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CarRacingSimulatorPawn.h"
#include "CarRacingSimulatorSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class CARRACINGSIMULATOR_API ACarRacingSimulatorSportsCar : public ACarRacingSimulatorPawn
{
	GENERATED_BODY()
	
public:

	ACarRacingSimulatorSportsCar();
};
