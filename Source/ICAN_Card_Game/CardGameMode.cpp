// Fill out your copyright notice in the Description page of Project Settings.
#include "CardGameMode.h"

void ACardGameMode::BeginPlay()
{
	Super::BeginPlay();

	OnStart();
}

void ACardGameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ACardGameMode, Deck);
}
