// Dev: Lord Savith - Source: GameDev.tv

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("%s spawned as commanded."), *GetName());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// reverse direction
	if (ShouldPlatformReturn())
	{
		// check how far it's moved
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();

		// add vector location
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);

		// Move platform
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s rotating..."), *GetName());
}

bool AMovingPlatform::ShouldPlatformReturn()
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Distance(StartLocation, GetActorLocation());;
}
