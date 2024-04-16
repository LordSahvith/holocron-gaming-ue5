// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InterpToMovementComponent.h"
#include "MyInterpToMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class MOVINGPLATFORMS_API UMyInterpToMovementComponent : public UInterpToMovementComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere,  Meta = (MakeEditWidget = true))
	FVector MoveToPosition1;	
	
};
