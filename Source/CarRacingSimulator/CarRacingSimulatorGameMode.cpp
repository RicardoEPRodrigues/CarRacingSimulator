// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRacingSimulatorGameMode.h"
#include "CarRacingSimulatorPlayerController.h"

ACarRacingSimulatorGameMode::ACarRacingSimulatorGameMode()
{
	PlayerControllerClass = ACarRacingSimulatorPlayerController::StaticClass();
}
