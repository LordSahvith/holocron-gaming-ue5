// DEV: Lord Savith ---- COURSE: GameDev.tv

#include "ToonTanksPlayerController.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    bPlayerEnabled ? GetPawn()->EnableInput(this) : GetPawn()->DisableInput(this);
    bShowMouseCursor = bPlayerEnabled;
}
