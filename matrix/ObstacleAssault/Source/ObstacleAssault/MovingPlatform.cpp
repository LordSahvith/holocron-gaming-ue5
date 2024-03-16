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
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalVector = MyVector;

	LocalVector.Z = MyVector.Z + 100;

	MyVector.Y = MyVector.Y + 1;

	SetActorLocation(LocalVector);

	// Move platform
		// get current location
		// add vector to that location
		// set the location
	// send platform back if gone too far
		// check how far it's moved
		// reverse direction
}

