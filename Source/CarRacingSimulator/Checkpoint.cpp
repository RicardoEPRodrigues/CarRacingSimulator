// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"

#include "CarRacingSimulatorPawn.h"
#include "Components/BoxComponent.h"


// Sets default values
ACheckpoint::ACheckpoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionComponent->SetCollisionProfileName(FName("OverlapAll"));
	CollisionComponent->InitBoxExtent({50, 100, 100});
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	CollisionComponent->SetShouldUpdatePhysicsVolume(false);
	CollisionComponent->SetCanEverAffectNavigation(false);
	CollisionComponent->SetupAttachment(RootComponent);

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckpoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACarRacingSimulatorPawn* Car = Cast<ACarRacingSimulatorPawn>(OtherActor);
	if (!Car)
	{
		return;
	}
	
	OnCarOverlap.Broadcast(this, Car);
}
