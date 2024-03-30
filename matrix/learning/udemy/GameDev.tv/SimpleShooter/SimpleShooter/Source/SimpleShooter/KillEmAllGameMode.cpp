// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "KillEmAllGameMode.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    UE_LOG(LogTemp, Warning, TEXT("Pawn Killed"));
}
