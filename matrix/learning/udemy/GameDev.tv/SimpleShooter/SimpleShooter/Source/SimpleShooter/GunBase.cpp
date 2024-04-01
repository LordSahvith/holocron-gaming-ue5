// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "GunBase.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGunBase::AGunBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootSceneComponent);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun Mesh"));
	Mesh->SetupAttachment(RootSceneComponent);
}

// Called when the game starts or when spawned
void AGunBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AGunBase::GunTrace(FHitResult &OutHit, FVector &OutShotDirection)
{
	AController *OwnerController = GetOwnerController();
	if (OwnerController == nullptr)
		return false;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location, Rotation);
	OutShotDirection = -Rotation.Vector();

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	FVector End = Location + Rotation.Vector() * MaxRange;
	return GetWorld()->LineTraceSingleByChannel(OutHit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController *AGunBase::GetOwnerController() const
{
	APawn *OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr)
		return nullptr;

	return OwnerPawn->GetController();
}

void AGunBase::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlashEffect, Mesh, TEXT("MuzzleFlashSocket"));

	FHitResult Hit;
	FVector ShotDirection;

	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());

		AActor *HitActor = Hit.GetActor();
		if (HitActor)
		{
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			AController *OwnerController = GetOwnerController();
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}
}
