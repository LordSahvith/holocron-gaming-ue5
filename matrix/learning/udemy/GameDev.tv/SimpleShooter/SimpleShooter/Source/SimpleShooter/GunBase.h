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
	class USceneComponent *RootSceneComponent;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent *Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem *MuzzleFlashEffect;

	UPROPERTY(EditAnywhere)
	USoundBase *MuzzleSoundEffect;

	UPROPERTY(EditAnywhere)
	UParticleSystem *ImpactFlashEffect;

	UPROPERTY(EditAnywhere)
	USoundBase *ImpactSoundEffect;

	UPROPERTY(EditAnywhere)
	float MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
	float Damage = 10.f;

	bool GunTrace(FHitResult &OutHit, FVector &OutShotDirection);

	AController *GetOwnerController() const;
};
