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
	ADeck* Deck;

	UPROPERTY(EditAnywhere)
	ADiscardedDeck* DiscardedDeck;

	UPROPERTY(EditAnywhere)
	AHand* Hand;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	static UCardCollectionsManager* Instance;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	bool MoveBetweenCollections(ACardCollection* A, ACardCollection* B, ACard* Card);

	UFUNCTION(BlueprintCallable, Category = "CardCollections singleton")
	static UCardCollectionsManager* GetInstance();

		
};
