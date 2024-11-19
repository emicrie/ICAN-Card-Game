// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReplicatedCardData.generated.h"

/**
 * 
 */

//Unused, but could be useful to use instead of an int array if we want to put more than static card data in the GameState
UCLASS(BlueprintType, DefaultToInstanced)
class ICAN_CARD_GAME_API UReplicatedCardData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int ID;
};
