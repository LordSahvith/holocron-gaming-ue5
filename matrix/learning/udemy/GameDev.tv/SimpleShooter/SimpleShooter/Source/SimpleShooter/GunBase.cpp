// DEV: Lord Savith -- COURSE: GameDev.tv Udemy

#include "GunBase.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"

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

void AGunBase::PullTrigger()
{
	UE_LOG(LogTemp, Warning, TEXT("and we're shooting....."));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
}
