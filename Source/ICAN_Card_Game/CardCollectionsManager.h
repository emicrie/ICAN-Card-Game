// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DiscardedDeck.h"
#include "Deck.h"
#include "Hand.h"
#include "CardCollectionsManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICAN_CARD_GAME_API UCardCollectionsManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCardCollectionsManager();

	UPROPERTY(EditAnywhere)
	ADeck* Deck = nullptr;

	UPROPERTY(EditAnywhere)
	ADiscardedDeck* DiscardedDeck = nullptr;

	UPROPERTY(EditAnywhere)
	AHand* Hand = nullptr;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	static UCardCollectionsManager* Instance;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	bool MoveBetweenCollections(ACardCollection* A, ACardCollection* B, ACard* Card, const int IndexToMoveAt = -1);

	static bool SwapCard(class ACard*& CardA, class ACard*& CardB);

	UFUNCTION(BlueprintCallable, Category = "CardCollections singleton")
	static UCardCollectionsManager* GetInstance();

	void DeselectHand();
	void SelectCard(ACard* Card);

	UPROPERTY()
	ACard* SelectedCard = nullptr;
	
	inline bool HasASelectedCardInHand() const {return SelectedCard != nullptr;}
};
