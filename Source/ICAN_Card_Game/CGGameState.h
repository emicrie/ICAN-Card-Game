// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"

#include "Engine/DataTable.h"
#include "ReplicatedCardCollectionManager.h"

#include "ReplicatedDeck.h"
#include "ReplicatedPlayedCards.h"

#include "PlayedCardMat.h"

#include "CGGameState.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACGGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "New system")
	TObjectPtr<UDataTable> DeckDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "New system | Base Card Collections | Played Cards")
	TSubclassOf<APlayedCardMat> PlayedCardsCollectionToUse;


	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "New System | Played Cards Settings")
	TObjectPtr<APlayedCardMat> PlayedCards;

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();

	virtual void BeginPlay() override;

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
