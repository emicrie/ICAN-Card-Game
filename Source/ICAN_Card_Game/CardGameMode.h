// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "Engine/DataTable.h"
#include "Deck.h"
#include "PlayedCardMat.h"

#include "CardGameMode.generated.h"

class ACardGameFSM;

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACardGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Deck")
	TSubclassOf<ADeck> DeckCollectionToUse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Played Cards")
	TSubclassOf<APlayedCardMat> PlayedCardsCollectionToUse;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Spawned Card Collections | Deck Settings")
	ADeck* Deck;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Spawned Card Collections | Played Cards Settings")
	APlayedCardMat* PlayedCards;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "State Machine")
	ACardGameFSM* StateMachine;
	
protected:
	virtual void BeginPlay() override;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
