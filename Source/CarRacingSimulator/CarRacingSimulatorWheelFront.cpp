// Copyright Epic Games, Inc. All Rights Reserved.

#include "CarRacingSimulatorWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UCarRacingSimulatorWheelFront::UCarRacingSimulatorWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}