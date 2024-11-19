// Fill out your copyright notice in the Description page of Project Settings.
#include "CGGameState.h"

UReplicatedCardData* ACGGameState::CreateNewCardData(int ID)
{
	UReplicatedCardData* Data = NewObject<UReplicatedCardData>(this);
	if (Data)
	{
		Data->ID = ID;
	}
	return Data;
}
