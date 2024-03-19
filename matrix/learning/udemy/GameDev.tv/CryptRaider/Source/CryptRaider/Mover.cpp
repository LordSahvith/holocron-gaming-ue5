// Dev Lord Savith : Course: GameDev.tv

#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float MyFloat = 5;
	float* YourFloat = &MyFloat;
	UE_LOG(LogTemp, Display, TEXT("My Float: %f"), *YourFloat);

	AActor* Owner = GetOwner();
	FString OwnerName = Owner->GetActorNameOrLabel(); // using a struct FString or FVector use (*Owner).GetActorNameOrLabel();
	UE_LOG(LogTemp, Display, TEXT("%s....I am your Tick!!!"), *OwnerName);

	FVector OwnerLocation = Owner->GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("%s. Your location is: %s"), *OwnerName, *OwnerLocation.ToCompactString());
}

