// Dev: Lord Savith : Course: GameDev.tv

#include "Grabber.h"

#include "Engine/World.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator GrabberRotation = GetComponentRotation();
	UE_LOG(LogTemp, Display, TEXT("Grabber Rotation: %s"), *GrabberRotation.ToCompactString());

	float Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Display, TEXT("World Time: %f"), Time);
}
