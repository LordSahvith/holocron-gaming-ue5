// Dev: Lord Savith : Course: GameDev.tv

#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Display, TEXT("Trigger Component"));
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor *Actor = GetTriggeringActor();

    if (Actor != nullptr)
    {
        UPrimitiveComponent *Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());

        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
            Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        }

        Mover->SetShouldMove(true);
    }
    else
    {
        Mover->SetShouldMove(false);
    }
}

void UTriggerComponent::SetMover(UMover *NewMover)
{
    Mover = NewMover;
}

AActor *UTriggerComponent::GetTriggeringActor() const
{
    TArray<AActor *> Actors;
    GetOverlappingActors(Actors);

    for (AActor *Actor : Actors)
    {
        if (Actor->ActorHasTag(UnlockingTagName))
        {
            return Actor;
        }
    }

    return nullptr;
}
