// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "DeckActor.generated.h"

UCLASS()
class ICAN_CARD_GAME_API ADeckActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeckActor();

	UPROPERTY(EditAnywhere)
	int Capacity = 50;

	UPROPERTY(EditAnywhere)
	class ACardHand* CardHand = nullptr;

	UPROPERTY(EditAnywhere)
	class ADiscardedDeckActor* DiscardedDeck = nullptr;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class ACardHolder>> CardList;

	UFUNCTION()
	void FillDeck();

	UFUNCTION()
	void DrawCard(int NrOfCardsToDraw = 1);

	UFUNCTION()
	void PopulateHand(int NumberOfCardsToPutInHand);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<ACardHolder*> SpawnedCardsList;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
