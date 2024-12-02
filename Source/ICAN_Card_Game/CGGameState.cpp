// Fill out your copyright notice in the Description page of Project Settings.
#include "CGGameState.h"

#define CHECK_SUBCLASS_SET(x) checkf(x, TEXT("The variable %s hasn't been set. It is required to set its value in editor before starting the game!"));

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
	Super::BeginPlay();
#if 0
	CHECK_SUBCLASS_SET(DeckCollectionToUse);
	Deck = NewObject<UReplicatedDeck>(this, DeckCollectionToUse.GetDefaultObject()->GetClass());
	CHECK_SUBCLASS_SET(PlayedCardsCollectionToUse);
	PlayedCards = NewObject<UReplicatedPlayedCards>(this, PlayedCardsCollectionToUse.GetDefaultObject()->GetClass());
	CHECK_SUBCLASS_SET(ManagerToUse);
	CollectionManager = NewObject<UReplicatedCardCollectionManager>(this, ManagerToUse.GetDefaultObject()->GetClass());
	
	UE_LOG(LogTemp, Log, TEXT("GameState BeginPlay"));
	OnStart();
#endif
}

void ACGGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(ACGGameState, Deck);
	DOREPLIFETIME(ACGGameState, PlayedCards);
}
