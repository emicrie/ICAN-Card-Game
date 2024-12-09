// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Engine/DataTable.h"
#include "CardCollectionsManager.h"

#include "Deck.h"
#include "PlayedCardMat.h"

#include "CardGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACardGameMode : public AGameMode
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCardCollectionsManager* CardCollectionManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Deck")
	TSubclassOf<ADeck> DeckCollectionToUse;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Deck Settings")
	ADeck* Deck;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Played Cards")
	TSubclassOf<APlayedCardMat> PlayedCardsCollectionToUse;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Played Cards Settings")
	APlayedCardMat* PlayedCards;

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();
	
protected:
	virtual void BeginPlay() override;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
