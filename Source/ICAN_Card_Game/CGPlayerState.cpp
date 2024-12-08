// Fill out your copyright notice in the Description page of Project Settings.


#include "CGPlayerState.h"
#include "Net/UnrealNetwork.h"

void ACGPlayerState::BeginPlay()
{
	Super::BeginPlay();

	OnStart();
}

void ACGPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACGPlayerState, Hand);
}
