// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRacingSimulatorWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UCarRacingSimulatorWheelRear::UCarRacingSimulatorWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}