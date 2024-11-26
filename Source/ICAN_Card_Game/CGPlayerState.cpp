// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPlayerState.h"
#include "Net/UnrealNetwork.h"

#define CHECK_SUBCLASS_SET(x) checkf(x, TEXT("The variable %s hasn't been set. It is required to set its value in editor before starting the game!"));

ACGPlayerState::ACGPlayerState()
{
	bReplicates = true;
}

void ACGPlayerState::BeginPlay()
{
	CHECK_SUBCLASS_SET(HandCollectionToUse);
	Hand = NewObject<UReplicatedHand>(this, HandCollectionToUse.GetDefaultObject()->GetClass());
}

void ACGPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACGPlayerState, Hand);
}
