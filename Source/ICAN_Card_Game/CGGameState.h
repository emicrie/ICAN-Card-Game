// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Engine/DataTable.h"
#include "CGGameState.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACGGameState : public AGameState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Card Collections | Deck")
	TObjectPtr<UDataTable> DeckDataTable;
};
