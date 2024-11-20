// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReplicatedCardCollection.h"
#include "ReplicatedDeck.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API UReplicatedDeck : public UReplicatedCardCollection
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cards Settings")
	TObjectPtr<UDataTable> DeckDataTable;


	//*--- ACardCollectionInterface
	virtual bool AddCard(class UReplicatedCardData* Card) override;
	virtual bool RemoveCard(class UReplicatedCardData* Card) override;
	//*--- End of ACardCollectionInterface
};
