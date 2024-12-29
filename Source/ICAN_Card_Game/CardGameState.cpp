// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameState.h"
#include "Net/UnrealNetwork.h"

void ACardFSMState::Tick(float DetaTime)
{
	if (bActiveState)
	{
		TickDelegate();
	}
}

void ACardFSMState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACardFSMState, bActiveState);
}
