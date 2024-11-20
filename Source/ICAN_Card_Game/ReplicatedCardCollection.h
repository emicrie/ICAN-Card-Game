// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReplicatedCardData.h"
#include "ReplicatedCardCollection.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ICAN_CARD_GAME_API UReplicatedCardCollection : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<UReplicatedCardData*> Elements;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "!bInfiniteCapacity"))
	int MaxCapacity = 99;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bInfiniteCapacity = false;

	//Should only be used for PlayedCardsMat, as it needs empty cards to function correctly
	UFUNCTION(BlueprintCallable)
	virtual void InitCollection();

	UFUNCTION(BlueprintCallable)
	virtual bool AddCard(UReplicatedCardData* Data);

	UFUNCTION(BlueprintCallable)
	virtual bool SetCard(UReplicatedCardData* Data, const int Index);

	UFUNCTION(BlueprintCallable)
	virtual bool RemoveCard(UReplicatedCardData* Data);

	UFUNCTION(BlueprintCallable)
	virtual void UpdateCollectionVisuals();

	UFUNCTION(BlueprintCallable)
	virtual bool Shuffle();

	UFUNCTION(BlueprintCallable)
	virtual bool IsCollectionFull();
	
};
