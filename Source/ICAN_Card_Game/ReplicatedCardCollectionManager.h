// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReplicatedCardCollectionManager.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API UReplicatedCardCollectionManager : public UObject
{
	GENERATED_BODY()

protected:

public:
	bool MoveBetweenCollections(UReplicatedCardCollectionManager* A, UReplicatedCardCollectionManager* B, int*& Card, const int IndexToMoveAt = -1);

	static bool SwapCard(int*& CardAID, int*& CardBID);
	
};
