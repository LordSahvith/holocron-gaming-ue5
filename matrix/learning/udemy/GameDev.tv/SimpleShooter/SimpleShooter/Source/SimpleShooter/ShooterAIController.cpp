// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "ShooterAIController.h"
#include "kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior)
    {
        RunBehaviorTree(AIBehavior);
    }
}

// Called every frame
void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
