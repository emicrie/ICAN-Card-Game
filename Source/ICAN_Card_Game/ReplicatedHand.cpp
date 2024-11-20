// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicatedHand.h"

bool UReplicatedHand::AddCard(UReplicatedCardData* Data)
{
	if (Data && Elements.Num() < MaxCapacity)
	{
		Elements.Add(Data);
		Data->Status = EReplicatedCardStatus::IN_HAND;
		UpdateCollectionVisuals();
		return true;
	}

	return false;
}

bool UReplicatedHand::RemoveCard(UReplicatedCardData* Data)
{
	if (Data && Elements.Num() > 0)
	{
		Elements.Remove(Data);
		UpdateCollectionVisuals();
		return true;
	}

	return false;
}