// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReplicatedCardCollection.h"
#include "ReplicatedHand.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API UReplicatedHand : public UReplicatedCardCollection
{
	GENERATED_BODY()

public:
	//*--- ACardCollectionInterface
	virtual bool AddCard(class UReplicatedCardData* Data) override;
	virtual bool RemoveCard(class UReplicatedCardData* Data) override;
	inline virtual ECardCollectionType GetCollectionType() override;
	//*--- End of ACardCollectionInterface
	
};
