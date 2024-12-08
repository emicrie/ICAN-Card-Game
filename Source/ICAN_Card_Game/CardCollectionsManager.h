// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiscardedDeck.h"
#include "CGPlayerState.h"
#include "Deck.h"
#include "Hand.h"
#include "CardCollectionsManager.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ICAN_CARD_GAME_API UCardCollectionsManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCardCollectionsManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	static UCardCollectionsManager* Instance;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintCallable)
	bool MoveBetweenCollections(ACardCollection* A, ACardCollection* B, int CardID, const int IndexToMoveAt = -1, ACGPlayerState* PlayerState = nullptr);

	UFUNCTION(BlueprintCallable)
	static bool SwapCard(class ACard*& CardA, class ACard*& CardB);

	UFUNCTION(BlueprintCallable, Category = "CardCollections singleton")
	static UCardCollectionsManager* GetInstance();

	void DeselectHand();
	void SelectCard(ACard* Card);

	UFUNCTION(BlueprintImplementableEvent)
	void MoveBetweenCollectionsBP(ACardCollection* A, ACardCollection* B, int CardID, const int IndexToMoveAt = -1, ACGPlayerState* PlayerState = nullptr);

	UPROPERTY()
	ACard* SelectedCard = nullptr;
	
	inline bool HasASelectedCardInHand() const {return SelectedCard != nullptr;}
};
