// DEV: Lord Savith ---- COURSE: GameDev.tv

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class ATank *Tank;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRange = 1000.f;
};
