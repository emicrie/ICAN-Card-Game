// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"

#include "Engine/DataTable.h"
#include "ReplicatedCardCollectionManager.h"

#include "ReplicatedDeck.h"
#include "ReplicatedPlayedCards.h"

#include "CGGameState.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACGGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Deck")
	TSubclassOf<UReplicatedDeck> DeckCollectionToUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Played Cards")
	TSubclassOf<UReplicatedPlayedCards> PlayedCardsCollectionToUse;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	int DeckSize;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	UReplicatedDeck* Deck;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Played Cards Settings")
	UReplicatedPlayedCards* PlayedCards;

	UPROPERTY(BlueprintReadOnly, Category = "Collection Manager")
	TObjectPtr<UReplicatedCardCollectionManager> CollectionManager;

	UFUNCTION(BlueprintCallable)
	UReplicatedCardData* CreateNewCardData(int ID);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();

	virtual void BeginPlay() override;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
