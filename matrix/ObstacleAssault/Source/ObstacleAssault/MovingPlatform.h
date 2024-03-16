// Dev: Lord Savith - Source: GameDev.tv

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 MyInt = 4;

	UPROPERTY(EditAnywhere)
	bool IsHavingFun = true;
	
	UPROPERTY(EditAnywhere)
	float MyFloat = 4.20;

	UPROPERTY(EditAnywhere)
	float InputFloatA = 2.3;

	UPROPERTY(EditAnywhere)
	float InputFloatB = 3.2;

	UPROPERTY(EditAnywhere)
	float APlusBFloat = 0.0;
};
