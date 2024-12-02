// Fill out your copyright notice in the Description page of Project Settings.
#include "CardGameMode.h"

#define CHECK_SUBCLASS_SET(x) checkf(x, TEXT("The variable %s hasn't been set. It is required to set its value in editor before starting the game!"));

UReplicatedCardData* ACardGameMode::CreateNewCardData(int ID)
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

void ACardGameMode::BeginPlay()
{
	//Super::BeginPlay();
	//
	//CHECK_SUBCLASS_SET(DeckCollectionToUse);
	//Deck = NewObject<UReplicatedDeck>(this, DeckCollectionToUse.GetDefaultObject()->GetClass());
	//CHECK_SUBCLASS_SET(PlayedCardsCollectionToUse);
	//PlayedCards = NewObject<UReplicatedPlayedCards>(this, PlayedCardsCollectionToUse.GetDefaultObject()->GetClass());
	//CHECK_SUBCLASS_SET(ManagerToUse);
	//CollectionManager = NewObject<UReplicatedCardCollectionManager>(this, ManagerToUse.GetDefaultObject()->GetClass());
	//
	//UE_LOG(LogTemp, Log, TEXT("GameMode BeginPlay"));

	OnStart();
}

void ACardGameMode::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ACardGameMode, Deck);
}
