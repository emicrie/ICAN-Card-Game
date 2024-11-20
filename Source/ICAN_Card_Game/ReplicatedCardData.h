// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReplicatedCardData.generated.h"

UENUM(BlueprintType)
enum class EReplicatedCardStatus : uint8 {
	IN_DECK = 0 UMETA(DisplayName = "DECK"),
	IN_HAND = 1  UMETA(DisplayName = "HAND"),
	IN_DISCARD = 2     UMETA(DisplayName = "DISCARD"),
	IN_SLOT = 3     UMETA(DisplayName = "IN_SLOT")
};

//Unused, but could be useful to use instead of an int array if we want to put more than static card data in the GameState
UCLASS(BlueprintType, DefaultToInstanced)
class ICAN_CARD_GAME_API UReplicatedCardData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "From DataTable (Static)")
	int ID = -1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "From Gameplay (Dynamic)", meta = (AllowPrivateAccess = "true"))
	EReplicatedCardStatus Status = EReplicatedCardStatus::IN_DECK;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "From Gameplay (Dynamic)")
	bool bIsCardSet = false;
};
