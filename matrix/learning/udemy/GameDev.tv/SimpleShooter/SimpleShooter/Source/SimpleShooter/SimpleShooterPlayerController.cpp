// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "SimpleShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ASimpleShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
    if (LoseScreen)
    {
        LoseScreen->AddToViewport();
    }
    
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
