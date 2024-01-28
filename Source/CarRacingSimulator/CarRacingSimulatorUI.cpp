// Copyright Epic Games, Inc. All Rights Reserved.


#include "CarRacingSimulatorUI.h"

void UCarRacingSimulatorUI::UpdateSpeed(float NewSpeed)
{
	// format the speed to KPH or MPH
	float FormattedSpeed = FMath::Abs(NewSpeed) * (bIsMPH ? 0.022f : 0.036f);

	// call the Blueprint handler
	OnSpeedUpdate(FormattedSpeed);
}

void UCarRacingSimulatorUI::UpdateGear(int32 NewGear)
{
	// call the Blueprint handler
	OnGearUpdate(NewGear);
}

void UCarRacingSimulatorUI::UpdateLaps(int CurrentLap)
{
	OnLapUpdate(CurrentLap);
}

void UCarRacingSimulatorUI::UpdateBoost(float Boost)
{
	OnBoostUpdate(Boost);
}
