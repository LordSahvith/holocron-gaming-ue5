// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "SimpleShooterPlayerController.h"
#include "TimerManager.h"

void ASimpleShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);
    
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
