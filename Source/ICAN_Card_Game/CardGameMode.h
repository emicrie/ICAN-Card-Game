// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Engine/DataTable.h"
#include "ReplicatedCardCollectionManager.h"

#include "ReplicatedDeck.h"
#include "ReplicatedPlayedCards.h"

#include "CardGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACardGameMode : public AGameMode
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Manager")
	TSubclassOf<UReplicatedCardCollectionManager> ManagerToUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Deck")
	TSubclassOf<UReplicatedDeck> DeckCollectionToUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Played Cards")
	TSubclassOf<UReplicatedPlayedCards> PlayedCardsCollectionToUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	int DeckSize;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	UReplicatedDeck* Deck;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Played Cards Settings")
	UReplicatedPlayedCards* PlayedCards;

	UPROPERTY(BlueprintReadOnly, Category = "Collection Manager")
	TObjectPtr<UReplicatedCardCollectionManager> CollectionManager;

	UFUNCTION(BlueprintCallable)
	UReplicatedCardData* CreateNewCardData(int ID);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();
	
protected:
	virtual void BeginPlay() override;
};
