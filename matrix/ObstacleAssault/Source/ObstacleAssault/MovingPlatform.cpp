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

	UE_LOG(LogTemp, Display, TEXT("Platform %s spawned as commanded."), *GetName());
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// get current location
	FVector CurrentLocation = GetActorLocation();
	
	// add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	
	// set the location - Move platform
	SetActorLocation(CurrentLocation);
	
	// check how far it's moved
	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
	
	// reverse direction - send platform back if gone too far
	if (DistanceMoved > MoveDistance) 
	{
		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Warning, TEXT("Platform: %s over shot by: %f"), *GetName(), OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

