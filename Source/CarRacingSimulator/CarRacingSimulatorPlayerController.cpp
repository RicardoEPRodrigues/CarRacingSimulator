// Copyright Epic Games, Inc. All Rights Reserved.


#include "CarRacingSimulatorPlayerController.h"
#include "CarRacingSimulatorPawn.h"
#include "CarRacingSimulatorUI.h"
#include "EnhancedInputSubsystems.h"
#include "ChaosWheeledVehicleMovementComponent.h"

void ACarRacingSimulatorPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	// spawn the UI widget and add it to the viewport
	VehicleUI = CreateWidget<UCarRacingSimulatorUI>(this, VehicleUIClass);

	check(VehicleUI);

	VehicleUI->AddToViewport();
}

void ACarRacingSimulatorPlayerController::Tick(float Delta)
{
	Super::Tick(Delta);

	if (IsValid(VehiclePawn) && IsValid(VehicleUI))
	{
		VehicleUI->UpdateSpeed(VehiclePawn->GetChaosVehicleMovement()->GetForwardSpeed());
		VehicleUI->UpdateGear(VehiclePawn->GetChaosVehicleMovement()->GetCurrentGear());
		VehicleUI->UpdateLaps(VehiclePawn->CurrentLap);
		VehicleUI->UpdateBoost(VehiclePawn->Boost);
	}
}

void ACarRacingSimulatorPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// get a pointer to the controlled pawn
	VehiclePawn = CastChecked<ACarRacingSimulatorPawn>(InPawn);
}

void ACarRacingSimulatorPlayerController::SetUIVisibility(bool bIsVisible)
{
	if (IsValid(VehicleUI))
	{
		VehicleUI->SetVisibility(bIsVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}