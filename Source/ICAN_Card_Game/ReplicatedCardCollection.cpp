// Fill out your copyright notice in the Description page of Project Settings.


#include "ReplicatedCardCollection.h"

void UReplicatedCardCollection::InitCollection()
{
	Elements.AddDefaulted(bInfiniteCapacity ? 99 : MaxCapacity);
}

bool UReplicatedCardCollection::AddCard(UReplicatedCardData* Data)
{
	if (Elements.Num() < MaxCapacity)
	{
		Elements.Insert(Data, 0);
		Data->Status = EReplicatedCardStatus::IN_DECK;
		return true;
	}

	return false;
}

bool UReplicatedCardCollection::SetCard(UReplicatedCardData* Data, const int Index)
{
	if (Index < MaxCapacity)
	{
		if (Data != nullptr)
		{
			Elements[Index] = Data;
			Elements[Index]->bIsCardSet = true;
		}

		return true;
	}
	return false;
}

bool UReplicatedCardCollection::RemoveCard(UReplicatedCardData* Data)
{
	return true;
}

bool UReplicatedCardCollection::Shuffle()
{
	return true;
}

bool UReplicatedCardCollection::IsCollectionFull()
{
	return Elements.Num() == MaxCapacity;
}

ECardCollectionType UReplicatedCardCollection::GetCollectionType()
{
	return ECardCollectionType::NONE;
}

void UReplicatedCardCollection::UpdateCollectionVisuals()
{
	OnCollectionChanged.Broadcast(this);
}

void UReplicatedCardCollection::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UReplicatedCardCollection, Elements);
}