// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicatedCardCollectionManager.h"

bool UReplicatedCardCollectionManager::SwapCard(int*& CardAID, int*& CardBID)
{
	if (CardAID && CardBID)
	{
		::Swap(CardAID, CardBID);
		return true;
	}
	return false;
}
