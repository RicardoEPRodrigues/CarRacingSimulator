// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCarOverlap, class ACheckpoint*, Checkpoint,
                                             class ACarRacingSimulatorPawn*, Car);

UENUM()
enum class ECheckpointType : uint8
{
	Start UMETA(DisplayName = "Start Checkpoint"),
	Optional UMETA(DisplayName = "Optional Checkpoint"),
	Normal UMETA(DisplayName = "Normal Checkpoint")
};

UCLASS()
class CARRACINGSIMULATOR_API ACheckpoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACheckpoint();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Config")
	ECheckpointType Type = ECheckpointType::Normal;

	UPROPERTY(EditAnywhere, Category="Collision")
	class UBoxComponent* CollisionComponent;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(BlueprintAssignable, Category="Collision")
	FOnCarOverlap OnCarOverlap;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
