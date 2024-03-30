// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "KillEmAllGameMode.h"
#include "SimpleShooterPlayerController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    ASimpleShooterPlayerController* PlayerController = Cast<ASimpleShooterPlayerController>(PawnKilled->GetController());
    if (PlayerController)
    {
        PlayerController->GameHasEnded(nullptr, false);
    }
}
