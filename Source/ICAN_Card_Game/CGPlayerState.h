// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "ReplicatedHand.h"
#include "Hand.h"

#include "CGPlayerState.generated.h"

//We might not need to replicated hands, but just in case we want a visual about it, I think it's best to put it in PlayerState
UCLASS()
class ICAN_CARD_GAME_API ACGPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ACGPlayerState();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Card Collections | Hand")
	TSubclassOf<UReplicatedHand> HandCollectionToUse;

	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Hand Settings")
	UReplicatedHand* Hand;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Hand Settings")
	int HandSize;

	UFUNCTION(BlueprintImplementableEvent)
	void ServerRequestOwnHand();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTest();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDrawCard();

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	
};
