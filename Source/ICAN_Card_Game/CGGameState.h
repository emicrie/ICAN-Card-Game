// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"

#include "Engine/DataTable.h"
#include "ReplicatedCardData.h"
#include "ReplicatedCardCollectionManager.h"

#include "CGGameState.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACGGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All cards Settings")
	TObjectPtr<UDataTable> CardsDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	int DeckSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	TArray<UReplicatedCardData*> Deck;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Played Cards Settings")
	TArray<UReplicatedCardData*> PlayedCards;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collection Manager")
	TObjectPtr<UReplicatedCardCollectionManager> CollectionManager;

	UFUNCTION(BlueprintCallable)
	UReplicatedCardData* CreateNewCardData(int ID);
};
