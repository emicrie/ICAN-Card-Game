// Fill out your copyright notice in the Description page of Project Settings.
#include "CGGameState.h"

UReplicatedCardData* ACGGameState::CreateNewCardData(int ID)
{
	UReplicatedCardData* Data = NewObject<UReplicatedCardData>(this);
	if (Data)
	{
		Data->ID = ID;
		Data->Status = EReplicatedCardStatus::IN_DECK;
		Data->bIsCardSet = false;
	}
	return Data;
}

void ACGGameState::BeginPlay()
{
	CollectionManager = NewObject<UReplicatedCardCollectionManager>(this);

	Deck = NewObject<UReplicatedDeck>(this, DeckCollectionToUse.GetDefaultObject()->GetClass());
	PlayedCards = NewObject<UReplicatedPlayedCards>(this, PlayedCardsCollectionToUse.GetDefaultObject()->GetClass());

	OnStart();
}
