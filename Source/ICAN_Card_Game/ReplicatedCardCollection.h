// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReplicatedCardData.h"
#include "CardCollectionDelegates.h"
#include "Net/UnrealNetwork.h"
#include "ReplicatedCardCollection.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ICAN_CARD_GAME_API UReplicatedCardCollection : public UObject, public ICardCollectionInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite)
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

protected:
	UPROPERTY(BlueprintAssignable, Category = "Delegates")
	FOnCollectionChanged OnCollectionChanged;

	virtual ECardCollectionType GetCollectionType() override;


public:
	virtual FOnCollectionChanged& GetOnCollectionChanged() override { return OnCollectionChanged; }

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
