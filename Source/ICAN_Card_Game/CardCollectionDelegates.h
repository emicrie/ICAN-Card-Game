// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CardCollectionDelegates.generated.h"

class UReplicatedCardData;
class UCardCollection;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectionChanged, const UReplicatedCardCollection*, UpdatedCollection);

UENUM(BlueprintType)
enum class ECardCollectionType : uint8
{
    NONE,
    DECK,
    HAND,
    SLOT,
    DISCARD
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UCardCollectionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ICAN_CARD_GAME_API ICardCollectionInterface
{
    GENERATED_BODY()

public:
	virtual FOnCollectionChanged& GetOnCollectionChanged() = 0;
    virtual ECardCollectionType GetCollectionType() = 0;
};
