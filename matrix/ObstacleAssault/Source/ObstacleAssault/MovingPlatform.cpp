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
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move platform
		// get current location
	FVector CurrentLocation = GetActorLocation();
		// add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// set the location
	SetActorLocation(CurrentLocation);
	// send platform back if gone too far
		// check how far it's moved
	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
		// reverse direction
	if (DistanceMoved > MoveDistance) 
	{
		PlatformVelocity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}
}

