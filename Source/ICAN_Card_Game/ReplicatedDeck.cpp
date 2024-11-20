// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicatedDeck.h"

bool UReplicatedDeck::AddCard(UReplicatedCardData* Data)
{
	if (Elements.Num() < MaxCapacity)
	{
		Elements.Insert(Data, 0);
		Data->Status = EReplicatedCardStatus::IN_DECK;
		UpdateCollectionVisuals();
		return true;
	}

	return false;
}

bool UReplicatedDeck::RemoveCard(UReplicatedCardData* Data)
{
	if (Elements.Num() > 0)
	{
		Elements.Remove(Data);
		return true;
	}

	return false;
}