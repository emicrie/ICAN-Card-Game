// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicatedPlayedCards.h"

bool UReplicatedPlayedCards::AddCard(UReplicatedCardData* Data)
{
	if (Data && Elements.Num() < MaxCapacity)
	{
		Elements.Insert(Data, 0);
		Data->Status = EReplicatedCardStatus::IN_SLOT;
		Elements[0]->bIsCardSet = true;
		return true;
	}

	return false;
}

bool UReplicatedPlayedCards::RemoveCard(UReplicatedCardData* Data)
{
	return Super::RemoveCard(Data);
}

bool UReplicatedPlayedCards::SetCard(UReplicatedCardData* Data, const int Index)
{
	//Sanity check, thanks to CardCollection's Initialize, the cards should never be empty
	if (Elements.IsEmpty())
	{
		Elements.AddDefaulted(MaxCapacity);
	}

	if (Index < MaxCapacity)
	{
		if (Data != nullptr)
		{
			Elements[Index] = Data;
			Elements[Index]->bIsCardSet = true;
		}

		if (IsCollectionFull())
		{
			UE_LOG(LogTemp, Warning, TEXT("The played mat has been filled!"));
		}
		return true;
	}

	return false;
}

void UReplicatedPlayedCards::InitCollection()
{
	Super::InitCollection();
}

bool UReplicatedPlayedCards::IsCollectionFull()
{
	bool bIsFull = true;
	for (int i = 0; i < MaxCapacity; i++)
	{
		if (!Elements[i])
		{
			bIsFull = false;
		}
	}
	return bIsFull;
}