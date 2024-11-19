// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ICAN_CARD_GAME_API ACGPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int> Hand;

	UFUNCTION(BlueprintImplementableEvent)
	void OnTest();
	
};
