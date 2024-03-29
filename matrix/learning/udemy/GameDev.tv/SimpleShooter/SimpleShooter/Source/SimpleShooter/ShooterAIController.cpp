// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "ShooterAIController.h"
#include "kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    SetFocus(PlayerPawn);
}

// Called every frame
void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    MoveToActor(PlayerPawn, 200.f);
}
