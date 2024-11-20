// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReplicatedCardData.h"
#include "ReplicatedCardCollectionManager.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ICAN_CARD_GAME_API UReplicatedCardCollectionManager : public UObject
{
	GENERATED_BODY()

protected:

public:
	bool MoveBetweenCollections(class UReplicatedCardCollection* A, class UReplicatedCardCollection* B, UReplicatedCardData* CardData, const int IndexToMoveAt = -1);

	static bool SwapCard(UReplicatedCardData*& CardAID, UReplicatedCardData*& CardBID);
	
};
