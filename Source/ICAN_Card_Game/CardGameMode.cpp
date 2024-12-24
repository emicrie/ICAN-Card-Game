// Fill out your copyright notice in the Description page of Project Settings.
#include "CardGameMode.h"
#include "Net/UnrealNetwork.h"

void ACardGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ACardGameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ACardGameMode, Deck);
	DOREPLIFETIME(ACardGameMode, PlayedCards);
}
