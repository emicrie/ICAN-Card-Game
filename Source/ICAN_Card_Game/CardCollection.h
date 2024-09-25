// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.h"
#include "CardCollection.generated.h"

UCLASS(Abstract, Blueprintable)
class ICAN_CARD_GAME_API ACardCollection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACardCollection();

	UPROPERTY(EditAnywhere)
	TArray<ACard*> Cards;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bInfiniteCapacity"))
	int MaxCapacity = 99;

	UPROPERTY(EditAnywhere)
	bool bInfiniteCapacity = false;

	UFUNCTION(BlueprintCallable)
	virtual bool AddCard(ACard* Card);

	UFUNCTION(BlueprintCallable)
	virtual bool RemoveCard(ACard* Card);

	UFUNCTION(BlueprintCallable)
	virtual void UpdateCollectionVisuals();

	UFUNCTION(BlueprintCallable)
	virtual bool Shuffle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
