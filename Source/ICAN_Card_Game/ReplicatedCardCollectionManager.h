// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReplicatedCardData.h"
#include "ReplicatedCardCollectionManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ICAN_CARD_GAME_API UReplicatedCardCollectionManager : public UObject
{
	GENERATED_BODY()

public:
	bool MoveBetweenCollections(class UReplicatedCardCollection* A, class UReplicatedCardCollection* B, UReplicatedCardData* CardData, const int IndexToMoveAt = -1);
	bool AddCard(UReplicatedCardCollection* A, UReplicatedCardData* CardData);

	static bool SwapCard(UReplicatedCardData*& CardAID, UReplicatedCardData*& CardBID);
};
