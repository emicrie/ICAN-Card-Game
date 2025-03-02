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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//*--- ACardCollectionInterface
	virtual bool AddCard(class ACard* Card) override;
	virtual bool RemoveCard(class ACard* Card) override;
	virtual void UpdateCollectionVisuals() override;
	//*--- End of ACardCollectionInterface

};
