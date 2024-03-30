// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterGameModeBase.generated.h"

UCLASS()
class SIMPLESHOOTER_API ASimpleShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled);
};
