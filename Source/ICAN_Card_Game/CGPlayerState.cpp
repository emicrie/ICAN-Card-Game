// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPlayerState.h"
#include "Net/UnrealNetwork.h"

ACGPlayerState::ACGPlayerState()
{
	bReplicates = true;
}

void ACGPlayerState::BeginPlay()
{
	Hand = NewObject<UReplicatedHand>(this, HandCollectionToUse.GetDefaultObject()->GetClass());
}

void ACGPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACGPlayerState, Hand);
}
