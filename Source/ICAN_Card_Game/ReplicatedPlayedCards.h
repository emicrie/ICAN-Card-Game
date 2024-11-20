// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReplicatedCardCollection.h"
#include "ReplicatedPlayedCards.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API UReplicatedPlayedCards : public UReplicatedCardCollection
{
	GENERATED_BODY()

	//*--- ACardCollectionInterface
	virtual bool AddCard(UReplicatedCardData* Data) override;
	virtual bool SetCard(UReplicatedCardData* Data, const int Index) override;
	virtual bool RemoveCard(UReplicatedCardData* Data) override;
	virtual void InitCollection() override;
	virtual bool IsCollectionFull() override;
	//*--- End of ACardCollectionInterface
	
};
