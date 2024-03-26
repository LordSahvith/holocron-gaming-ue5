// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunBase.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGunBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGunBase();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	class USceneComponent* RootSceneComponent;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	class UParticleSystem* MuzzleFlash;
};
