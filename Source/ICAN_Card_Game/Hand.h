// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CardCollection.h"
#include "Hand.generated.h"

UCLASS()
class ICAN_CARD_GAME_API AHand : public ACardCollection
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHand();

protected:
	virtual bool AddCard(int CardID, int PositionToMoveAt) override;

public:	
	//virtual bool AddCard(int CardID, int PositionToMoveAt = 0) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
